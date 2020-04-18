#include "stm32f103_hal\stm32f103_hal_interface.h"

int main(){
	enablePeripheralClock(Peripheral_GPIOC);
	configureGPIO(Peripheral_GPIOC,13,GPIO_MODE_OUT_10MHZ,GPIO_CONF_OUT_PUSHPULL);
	while(1) {
		setGPIOBit(Peripheral_GPIOC,13,0);
		for (int i = 0; i < 1000000; ++i) __asm__("nop");
		setGPIOBit(Peripheral_GPIOC,13,1);
		for (int i = 0; i <  500000; ++i) __asm__("nop");
    }	
}
