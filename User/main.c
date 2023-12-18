#include "LCD1602.H"
#include "SMG.H"
#include "HCSR04.H"

void main() {
	
	initHcSr04(); // ³õÊ¼»¯³¬Éù²¨Ä£¿é
	
	
	while(1) {
		getDistance();                        
	}
}