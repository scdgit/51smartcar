#ifndef _SG90_H_
#define _SG90_H_
#include "PUBLIC.H"

#define ROTATE_SPEEDE	500 

sbit PWM_PORT = P2^3;

extern u8 gAngle;
extern u8 g_sgTimer;
extern u8 gDirection;
extern u8 gEngineFlag;

void Angle45();
void Angle90();
void Angle115();
void StartEngine();

#endif