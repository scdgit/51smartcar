#include "SMG.H"

u8 gsmg_buf[16] = {0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e}; // 不带小数点
u8 gsmg_dp_buf[16] = {0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x10,0x08,0x03,0x46,0x21,0x06,0x0e}; // 带小数点

/**
 * 动态显示数码管
 */
void display_msg(u8 dat[], u8 pos) {
   u8 i;
   for (i = 0; i < pos; i++) {
      switch(i) {
         case 0: SMG_1 = 0, SMG_2 = 1;SMG_3 = 1; SMG_4 = 1; break;
			case 1: SMG_1 = 1, SMG_2 = 0;SMG_3 = 1; SMG_4 = 1; break;
			case 2: SMG_1 = 1, SMG_2 = 1;SMG_3 = 0; SMG_4 = 1; break;
			case 3: SMG_1 = 1, SMG_2 = 1;SMG_3 = 1; SMG_4 = 0; break;
      }
      SMG_4_PORT = dat[i];
      delay_ms(1);
      SMG_4_PORT = 0xff;
   }
}