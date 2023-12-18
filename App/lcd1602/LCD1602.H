#ifndef __LCD1602_H__
#define __LCD1602_H__
#include "PUBLIC.H"

#define LCD_PORT	P0

sbit LCD1602_RS = P2^3;
sbit LCD1602_RW = P2^4;
sbit LCD1602_E = P2^5;

void lcd1602_write_cmd(u8 cmd);
void lcd1602_write_dat(u8 dat);
void lcd1602_init();
void lcd1602_check_busy();
void lcd1602_display_string(u8 row, u8 col, u8 *str);
void lcd1602_updateUseStr(u8 row, u8 *str);
void lcd1602_updateUseHex(u8 row, u8 buf);
void lcd1602_defaultDisplay();

#endif