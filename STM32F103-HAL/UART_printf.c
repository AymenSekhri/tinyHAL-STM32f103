#include "tinyHAL/stm32f103_hal.h"

int main(){
	
	USARTInitiate(Peripheral_USART1, 0x1D4C, USART_MODE_TRANSMIT); // Baud Rate for 4.5Mhz in 9600bps is 468.75 (0x1D4 and 0xC)
	printf("hello there!"); // printf/scanf use USART1
	
}



