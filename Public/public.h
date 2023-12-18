#ifndef _PUBLIC_H_
#define _PUBLIC_H_
#include "REG52.H"

// ��ǰ��������ʾ
#define LCD_LINE1_TITLE "Output:"
#define LCD_LINE1_LEN 7

// ��ǰ������ʾ
#define LCD_LINE2_TITLE "Direction:"
#define LCD_LINE2_LEN 10

typedef unsigned char u8;
typedef unsigned int u16;

void delay_ms(u16 ms);
void delay_10us(u16 ten_us);

#endif