#include "KEY.H"
#include "HCSR04.H"

u8 gkeyNum = NO_KEY_DOWN;

// ��ת��ֵʵ�ֹ��ܵ�������ر�
void keyNumReverse(u8 val) {
	gkeyNum = (gkeyNum == val) ? NO_KEY_DOWN : val;
}

// ����ɨ��
void key_scan() {
	if (!K4) {
		// ������ģ�����������
		delay_ms(20);
		if (!K4) {
			while(!K4);
			keyNumReverse(K4_DOWN);
			if (gkeyNum == NO_KEY_DOWN)
				hcsr04ResetSmgBuf();
		}
	}
}