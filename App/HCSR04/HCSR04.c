#include "HCSR04.H"
#include "SMG.H"
#include "KEY.H"

bit gHc90Flag = 0; // 判断是否超出测量范围

u8 hc90_s = 0;

// 获取前方障碍物的距离
u8 GetDistance() {
	TH0 = 0;
	TL0 = 0;
	// 等待接收信号
	while(!EchoPort);
	TR0 = 1; // 开始计时
	while(EchoPort);
	TR0 = 0; // 计时结束
	// 计算距离(cm)
	hc90_s = (TH0 * 256 + TL0) * 0.034 / 2 + 1;
	if (hc90_s >= 51 || gHc90Flag) {
		Hcsr04ResetSmgBuf();
	} else {
		smg_buf[2] = gsmg_dp_buf[hc90_s / 100];
		smg_buf[1] = gsmg_buf[hc90_s % 100 / 10];
		smg_buf[0] = gsmg_buf[hc90_s % 10];
	}
	return hc90_s;
}

// 重置数码管的显示
void Hcsr04ResetSmgBuf() {
	gHc90Flag = 0;
	smg_buf[2] = SMG_NULL;
	smg_buf[1] = SMG_NULL;
	smg_buf[0] = SMG_NULL;
}


// 发送信号
void Hc90SendSignal() {
	TrigPort = 0;
	TrigPort = 1;
	delay_10us(2);
	TrigPort = 0;
}