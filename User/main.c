#include "LCD1602.H"
#include "SMG.H"
#include "HCSR04.H"
#include "KEY.H"

void main() {
	gkeyNum = NO_KEY_DOWN;
	initHcSr04(); // ��ʼ��������ģ��
	while(1) {
		key_scan();
		if (gkeyNum == K4_DOWN)
			getDistance();
	}
}