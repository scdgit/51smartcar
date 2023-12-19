#ifndef __HCSR04_H_
#define __HCSR04_H_
#include "PUBLIC.H"

sbit TrigPort = P2^6; // ����������
sbit EchoPort = P2^7; // ��������

void initHcSr04();
u8 getDistance();
void hcsr04ResetSmgBuf();

#endif