#include "LCD1602.H"
#include "SMG.H"
#include "HCSR04.H"
#include "SG90.H"
#include "TIMER.H"
#include "KEY.H"

void main() {
	u8 distance = 0;
	InitTimer();
	delay_ms(500);
	while(1) {
		//StartEngine(); // �������
		if (gTimer >= 1000) {
			// 0.1ms * 1000 = 100ms���һ��ǰ������
			//Hc90SendSignal(); // ��ɫ�ź�
			//distance = GetDistance();
			gTimer = 0;
		}
		
	}
}

