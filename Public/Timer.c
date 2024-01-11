#include "TIMER.H"
#include "HCSR04.H"
#include "SMG.H"

u8 smgTimer = 0;
u16 gTimer = 0; // 超声波的计时器
u16 gSgTimer = 0; // 舵机的计时器

// 初始化定时器
void InitTimer() {
    TMOD = 0x11;
    TH1 = 0xff;   //定时常数 100us 晶振为11.0592MHz
    TL1 = 0xa4;
    ET1 = 1; 
    TR1 = 1;
	 EA=1; 
}

// 定时器0
void Timer0() interrupt 1 {
	// 超声波测距溢出
	gHc90Flag = 0;
}

// 定时器1
void Timer1() interrupt 3 {
	TH1 = 0xff; // 0.1ms
	TL1 = 0xa4;
	
	gTimer++;
	gSgTimer++;
	
	// 2ms 扫描一次数码管
	smgTimer++;
	if (smgTimer >= 20) {
		display_msg(smg_buf, 3); // 0.2ms
		smgTimer = 0;
	}
	
	// 启动舵机
	StartEngine();
}