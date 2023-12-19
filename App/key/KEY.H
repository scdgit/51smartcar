#ifndef _KEY_H_
#define _KEY_H_
#include "PUBLIC.H"

#define K1_DOWN 1
#define K2_DOWN 2
#define K3_DOWN 3
#define K4_DOWN 4
#define NO_KEY_DOWN -1

sbit K1 = P2^7;
sbit K2 = P2^6;
sbit K3 = P2^5;
sbit K4 = P2^4;

extern u8 gkeyNum;

void key_scan();
void keyNumReverse(u8 val);

#endif