#include "KEY.H"
#include "HCSR04.H"

u8 gkeyNum = NO_KEY_DOWN;

// 反转键值实现功能的启动与关闭
void keyNumReverse(u8 val) {
	gkeyNum = (gkeyNum == val) ? NO_KEY_DOWN : val;
}

// 按键扫描
void key_scan() {
	if (!K4) {
		// 超声波模块的启动开关
		delay_ms(20);
		if (!K4) {
			while(!K4);
			keyNumReverse(K4_DOWN);
			if (gkeyNum == NO_KEY_DOWN)
				hcsr04ResetSmgBuf();
		}
	}
}