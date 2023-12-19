#include "HCSR04.H"
#include "SMG.H"
#include "INTRINS.H"

bit flag = 0; // �ж��Ƿ񳬳�������Χ

u8 smg_buf[3] = {SMG_NULL, SMG_NULL, SMG_NULL};
u8 timer = 0;
u8 s = 0;

// ��ʼ�����ö�ʱ��0�Ͷ�ʱ��1��������ʽΪ1
void initHcSr04() {
	TMOD |= 0x01;
	TH0 = 0;
	TL0 = 0;
	TH1 = 0X00;
	TL1 = 0X00;
	ET0 = 1; // ����T0�ж�
	ET1 = 1;
	TR1 = 1; // ������ʱ
	EA = 1; // �����ܿ���
}

// ��ȡǰ���ϰ���ľ���
u8 getDistance() {
	TH0 = 0;
	TL0 = 0;
	
	// �ȴ������ź�
	while(!EchoPort);
	TR0 = 1; // ��ʼ��ʱ
	while(EchoPort);
	TR0 = 0; // ��ʱ����
	
	// �������(cm)
	s = (TH0 * 256 + TL0) * 0.034 / 2;
	if (s > 50 || flag) {
		flag = 0;
		smg_buf[2] = SMG_NULL;
		smg_buf[1] = SMG_NULL;
		smg_buf[0] = SMG_NULL;
	} else {
		smg_buf[2] = gsmg_dp_buf[s / 100];
		smg_buf[1] = gsmg_buf[s % 100 / 10];
		smg_buf[0] = gsmg_buf[s % 10];
	}
	return s;
}

// ��ʱ���ʱ��˵������������Χ
void distanceExceed() interrupt 1 {
	flag = 1;
}

// ʹ�ö�ʱ������ʾ����ܺͷ��ͳ������ź�(��ʱ��1us��ʱ11.05926)
void distanceRestTimer() interrupt 3 {
	TH1 = 0X00;
	TL1 = 0X00;
	display_msg(smg_buf, 3); //(1ms��ʱ)
	timer++;
	if (timer >= 30) {
		// Լ30ms����һ���ź�
		TrigPort = 1;
		delay_10us(2);
		TrigPort = 0;
		timer = 0;
	}
}