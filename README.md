# 51智能小车

### 超声波模块

> HC-SR04模块采用IO口 TRIG 触发测距，至少给 10us 的高电平信号；模块自动发送 8 个 40khz 的方波，自动检测是否有信号返回；有信号返回 ECHO 输出一个高电平，电平持续的时间就是超声波发射到返回的时间。

#### 引脚说明

- Vcc：电源
- Trig：触发器引脚（发送信号）
- Echo：接收引脚（接收信号）
- Gnd：接地

#### 计算公式

测试距离=（高电平时间 * 声速（340 m/s））/ 2 

#### 驱动程序

HCSR04.H 头文件

```c
#ifndef __HCSR04_H_
#define __HCSR04_H_
#include "PUBLIC.H"

sbit TrigPort = P2^6; // 触发器引脚
sbit EchoPort = P2^7; // 接收引脚

void initHcSr04();
u8 getDistance();

#endif
```

HCSR04.c 文件

```c
#include "HCSR04.H"
#include "SMG.H"
#include "INTRINS.H"

bit flag = 0; // 判断是否超出测量范围

u8 smg_buf[3] = {SMG_NULL, SMG_NULL, SMG_NULL};
u8 timer = 0;
u8 s = 0;

// 初始化设置定时器0和定时器1，工作方式为1
void initHcSr04() {
	TMOD |= 0x01;
	TH0 = 0;
	TL0 = 0;
	TH1 = 0X00;
	TL1 = 0X00;
	ET0 = 1; // 允许T0中断
	ET1 = 1;
	TR1 = 1; // 开启定时
	EA = 1; // 开启总开关
}

// 获取前方障碍物的距离
u8 getDistance() {
	TH0 = 0;
	TL0 = 0;
	
	// 等待接收信号
	while(!EchoPort);
	TR0 = 1; // 开始计时
	while(EchoPort);
	TR0 = 0; // 计时结束
	
	// 计算距离(cm)
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

// 计时溢出时，说明超出测量范围
void distanceExceed() interrupt 1 {
	flag = 1;
}

// 使用定时器来显示数码管和发送超声波信号(定时器1us延时11.05926)
void distanceRestTimer() interrupt 3 {
	TH1 = 0X00;
	TL1 = 0X00;
	display_msg(smg_buf, 3); //(1ms延时 SMG.H)
	timer++;
	if (timer >= 30) {
		// 约30ms发送一次信号
		TrigPort = 1;
		delay_10us(2);
		TrigPort = 0;
		timer = 0;
	}
}
```

