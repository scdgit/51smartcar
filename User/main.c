#include "LCD1602.H"
#include "SMG.H"
#include "HCSR04.H"

void main() {
	
	initHcSr04(); // ��ʼ��������ģ��
	
	
	while(1) {
		getDistance();                        
	}
}