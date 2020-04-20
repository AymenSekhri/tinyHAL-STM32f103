#include "tinyHAL/stm32f103_hal.h"


int main(){
	
	enablePeripheralClock(Peripheral_GPIOC);
	configureGPIO(Peripheral_GPIOC, 13, GPIO_MODE_OUT_50MHZ, GPIO_CONF_OUT_PUSHPULL);
	
	initiateTimer(Peripheral_TIM2);
	while(1){		
		delay(1234); //delay uses TIM2
		toggleGPIOBit(Peripheral_GPIOC, 13);
	}
		
}



