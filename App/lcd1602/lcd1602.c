#include "LCD1602.H"


// 写入指令
void lcd1602_write_cmd(u8 cmd) {
	LCD1602_RS = 0;
	LCD1602_RW = 0;
	LCD1602_E = 0;
	LCD_PORT = cmd;
	delay_ms(1);
	LCD1602_E = 1;
	delay_ms(1);
	LCD1602_E = 0;
}


// 写入数据
void lcd1602_write_dat(u8 dat) {
	LCD1602_RS = 1;
	LCD1602_RW = 0;
	LCD1602_E = 0;
	LCD_PORT = dat;
	delay_ms(1);
	LCD1602_E = 1;
	delay_ms(1);
	LCD1602_E = 0;
}


// 初始化LCD
void lcd1602_init() {
	lcd1602_write_cmd(0x38);
	lcd1602_write_cmd(0x06);
	lcd1602_write_cmd(0x0c);
	// 清屏指令
	lcd1602_write_cmd(0x01);
}


// 忙信号检测
void lcd1602_check_busy() {
	do {
		LCD1602_RS = 0;
		LCD1602_RW = 1;
		LCD1602_E = 0;
		LCD_PORT = 0xff;
		LCD1602_E = 1;
	} while(LCD_PORT^7 == 1);
}


// 将指定的字符串依次写入LCD1602
void lcd1602_display_string(u8 row, u8 col, u8 *str) {
	u8 i = 0;
	if (row > 1 || col > 15) return;
	while(*str != '\0') {
		if (row == 0)
			// 显示在第一行
			lcd1602_write_cmd(0x80 + col + i); // 位置
		else
			// 显示在第二行
			lcd1602_write_cmd(0x80 + 0x40 + col + i); // 位置
		lcd1602_write_dat(*str); // 数据
		i++, str++;
	}
}


// 使用字符串更改显示
void lcd1602_updateUseStr(u8 row, u8 *str) {
	if (row == 0)
		lcd1602_display_string(0, LCD_LINE1_LEN + 1, str);
	else
		lcd1602_display_string(1, LCD_LINE2_LEN + 1, str);
}


// 使用十六进制进行更改
void lcd1602_updateUseHex(u8 row, u8 buf) {
	u8 bufs[2] = { 0x00, '\0' };
	bufs[0] = buf;
	if (row == 0)
		lcd1602_display_string(0, LCD_LINE1_LEN + 1, bufs);
	else
		lcd1602_display_string(1, LCD_LINE2_LEN + 1, bufs);
}


// 设置LCD的初始显示字符
void lcd1602_defaultDisplay() {
	lcd1602_init();
	lcd1602_display_string(0, 0, LCD_LINE1_TITLE);
	lcd1602_display_string(1, 0, LCD_LINE2_TITLE);
}