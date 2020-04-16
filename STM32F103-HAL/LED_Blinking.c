#include "stm32_hal.h"

int main(){
		//RCC->APB2ENR |= 0x10;
    //GPIOC->CRH = (GPIOC->CRH & 0xFF0FFFFF) | 0x00100000;
	
		enablePeripheralClock(Peripheral_GPIOC);
		configureGPIO(Peripheral_GPIOC,13,GPIO_MODE_OUT_10MHZ,GPIO_CONF_OUT_PUSHPULL);
		while(1) {
				setGPIOBit(Peripheral_GPIOC,13,0);
        for (int i = 0; i < 1000000; ++i) __asm__("nop");
        setGPIOBit(Peripheral_GPIOC,13,1);
        for (int i = 0; i <  500000; ++i) __asm__("nop");
    }
		
}

/*
Enable IO bit connecter to USART
Enable USART
Set Alternate Mode in AFR
Set Alternate Mode in the IO pin
Set Buad rate in BRR
Enable TX/RX
Enable USART
*/

/*
//Blink
int main(){
    RCC->APB2ENR |= 0x10;
    GPIOC->CRH = (GPIOC->CRH & 0xFF0FFFFF) | 0x00100000;
    //
    
		while(1) {
        GPIOC->ODR = ~(1<<13);//if it is Active Low
        for (int i = 0; i < 1000000; ++i) __asm__("nop");
        GPIOC->ODR |= 1<<13; //if it is Active High
        for (int i = 0; i <  500000; ++i) __asm__("nop");
    }
		
}

*/