#include "KEY.H"
#include "HCSR04.H"
#include "SG90.H"

u8 gkeyNum = NO_KEY_DOWN;

// ��ת��ֵʵ�ֹ��ܵ�������ر�
void keyNumReverse(u8 val) {
	if (gkeyNum == val) {
		gkeyNum = NO_KEY_DOWN;
		
	} else {
		gkeyNum = val;
		P0 = 0XFF;
	}
}

// ����ɨ��
void key_scan() {
	if (!K4) {
		TR1 = 0;
		// ������ģ�����������
		delay_ms(10);
		if (!K4) {
			TR1 = 1;
			keyNumReverse(K4_DOWN);
			gDirection = -1;
			if (gkeyNum == NO_KEY_DOWN) {
				gDirection = 0;
			}
				
		} else TR1 = 1;
	}
}