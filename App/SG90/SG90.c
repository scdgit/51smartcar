#include "SG90.H"

u8 gAngle = 12; // 8-12-17
u8 g_sgTimer = 0;
u8 gEngineFlag; // 舵机开关


// 舵机旋转到45度位置（右侧）
void Angle45() {
	gAngle = 10;
	delay_ms(500);
}

// 舵机旋转到90度位置（中间）
void Angle90() {
	gAngle = 13;
	delay_ms(500);
}

// 舵机旋转到115度位置（左侧）
void Angle115() {
	gAngle = 20;//舵机转动90度
	delay_ms(500);
}

void StartEngine() {
	if(g_sgTimer <= gAngle) //15 == 90°
		PWM_PORT = 1;
	else
		PWM_PORT = 0;
	g_sgTimer++;
	if (g_sgTimer >= 200) {
		//T = 20ms清零
		g_sgTimer = 0; 
	}
}