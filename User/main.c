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
		//StartEngine(); // 启动舵机
		if (gTimer >= 1000) {
			// 0.1ms * 1000 = 100ms检测一次前方距离
			//Hc90SendSignal(); // 发色信号
			//distance = GetDistance();
			gTimer = 0;
		}
		
	}
}

