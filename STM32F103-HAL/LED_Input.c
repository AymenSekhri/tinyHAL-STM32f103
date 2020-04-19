#include "tinyHAL/stm32f103_hal.h"

int main(){
	enablePeripheralClock(Peripheral_GPIOC);
	configureGPIO(Peripheral_GPIOC,13,GPIO_MODE_OUT_10MHZ,GPIO_CONF_OUT_PUSHPULL);
	
	enablePeripheralClock(Peripheral_GPIOC);
	configureGPIO(Peripheral_GPIOC,14,GPIO_MODE_IN,GPIO_CONF_IN_PUSHUP_PULLDOWN);
	while(1) {
		
		for (int i = 0; i < 1000000; ++i) __asm__("nop");
		setGPIOBit(Peripheral_GPIOC,13,readGPIOBit(Peripheral_GPIOC,14));
		for (int i = 0; i <  1000000; ++i) __asm__("nop");
    }
}
