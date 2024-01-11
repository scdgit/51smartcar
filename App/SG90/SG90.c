#include "SG90.H"

u8 gAngle = 12; // 8-12-17
u8 g_sgTimer = 0;
u8 gEngineFlag; // �������


// �����ת��45��λ�ã��Ҳࣩ
void Angle45() {
	gAngle = 10;
	delay_ms(500);
}

// �����ת��90��λ�ã��м䣩
void Angle90() {
	gAngle = 13;
	delay_ms(500);
}

// �����ת��115��λ�ã���ࣩ
void Angle115() {
	gAngle = 20;//���ת��90��
	delay_ms(500);
}

void StartEngine() {
	if(g_sgTimer <= gAngle) //15 == 90��
		PWM_PORT = 1;
	else
		PWM_PORT = 0;
	g_sgTimer++;
	if (g_sgTimer >= 200) {
		//T = 20ms����
		g_sgTimer = 0; 
	}
}