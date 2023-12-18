#ifndef _SMG_H_
#define _SMG_H_
#include "PUBLIC.H"

#define SMG_4_PORT	P0
#define SMG_NULL	0XBF

sbit SMG_1 = P2^3;
sbit SMG_2 = P2^2;
sbit SMG_3 = P2^1;
sbit SMG_4 = P2^0;

extern u8 gsmg_buf[16];
extern u8 gsmg_dp_buf[16];

void display_msg(u8 dat[], u8 pos);

#endif