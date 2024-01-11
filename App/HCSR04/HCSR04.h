#ifndef __HCSR04_H_
#define __HCSR04_H_
#include "PUBLIC.H"

sbit TrigPort = P2^6; // ����������
sbit EchoPort = P2^7; // ��������

extern bit gHc90Flag;

u8 GetDistance();
void Hcsr04ResetSmgBuf();
void Hc90SendSignal();

#endif