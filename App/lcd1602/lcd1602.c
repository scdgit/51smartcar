#include "LCD1602.H"


// д��ָ��
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


// д������
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


// ��ʼ��LCD
void lcd1602_init() {
	lcd1602_write_cmd(0x38);
	lcd1602_write_cmd(0x06);
	lcd1602_write_cmd(0x0c);
	// ����ָ��
	lcd1602_write_cmd(0x01);
}


// æ�źż��
void lcd1602_check_busy() {
	do {
		LCD1602_RS = 0;
		LCD1602_RW = 1;
		LCD1602_E = 0;
		LCD_PORT = 0xff;
		LCD1602_E = 1;
	} while(LCD_PORT^7 == 1);
}


// ��ָ�����ַ�������д��LCD1602
void lcd1602_display_string(u8 row, u8 col, u8 *str) {
	u8 i = 0;
	if (row > 1 || col > 15) return;
	while(*str != '\0') {
		if (row == 0)
			// ��ʾ�ڵ�һ��
			lcd1602_write_cmd(0x80 + col + i); // λ��
		else
			// ��ʾ�ڵڶ���
			lcd1602_write_cmd(0x80 + 0x40 + col + i); // λ��
		lcd1602_write_dat(*str); // ����
		i++, str++;
	}
}


// ʹ���ַ���������ʾ
void lcd1602_updateUseStr(u8 row, u8 *str) {
	if (row == 0)
		lcd1602_display_string(0, LCD_LINE1_LEN + 1, str);
	else
		lcd1602_display_string(1, LCD_LINE2_LEN + 1, str);
}


// ʹ��ʮ�����ƽ��и���
void lcd1602_updateUseHex(u8 row, u8 buf) {
	u8 bufs[2] = { 0x00, '\0' };
	bufs[0] = buf;
	if (row == 0)
		lcd1602_display_string(0, LCD_LINE1_LEN + 1, bufs);
	else
		lcd1602_display_string(1, LCD_LINE2_LEN + 1, bufs);
}


// ����LCD�ĳ�ʼ��ʾ�ַ�
void lcd1602_defaultDisplay() {
	lcd1602_init();
	lcd1602_display_string(0, 0, LCD_LINE1_TITLE);
	lcd1602_display_string(1, 0, LCD_LINE2_TITLE);
}