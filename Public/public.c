#include "PUBLIC.H"


// ∫¡√Î—” ±
void delay_ms(u16 ms) {
	u16 i, j;
   for (i = ms; i > 0; i--)
      for (j = 110; j > 0; j--);
}

// 100us—” ±
void delay_10us(u16 ten_us) {
   while (ten_us--);
}