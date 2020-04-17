#include "stm32_hal.h"
/*

TODO:
- polling for USART_STAT_TC should be replaced by interrupts.

*/

void enablePeripheralClock(int peripheral){
	int configurationBitmask = (1 << LOWERWORD(peripheral));
	switch(UPPERWORD(peripheral)){
		case BUS_AHB:
			RCC->AHBENR |= configurationBitmask;
			break;
		case BUS_APB1:
			RCC->APB1ENR |= configurationBitmask;
			break;
		case BUS_APB2:
			RCC->APB2ENR |= configurationBitmask;
			break;
	}
}

void configureGPIO(int port,int pin,int mode,int configuration){
	bool isLowerPort = pin<8?true:false;
	int configurationBitmask = 0;
	if(isLowerPort){
		configurationBitmask = mode<<(pin*2);
	}else{
		configurationBitmask = mode<<((pin-8)*2);
	}
	switch(port){
		case Peripheral_GPIOA:
			if(isLowerPort)
				GPIOA->CRL = (GPIOA->CRL & ~(0xF << (pin%8)*4) ) |  (mode | configuration << 2) << (pin%8)*4;
			else
				GPIOA->CRH = (GPIOA->CRH & ~(0xF << (pin%8)*4) ) |  (mode | configuration << 2) << (pin%8)*4;
			break;
		case Peripheral_GPIOB:
			if(isLowerPort)
				GPIOB->CRL = (GPIOB->CRL & ~(0xF << (pin%8)*4) ) |  (mode | configuration << 2) << (pin%8)*4;
			else
				GPIOB->CRH = (GPIOB->CRH & ~(0xF << (pin%8)*4) ) |  (mode | configuration << 2) << (pin%8)*4;
			break;
		case Peripheral_GPIOC:
			if(isLowerPort){
				GPIOC->CRL = (GPIOC->CRL & ~(0xF << (pin%8)*4) ) |  (mode | configuration << 2) << (pin%8)*4;
			}else
				GPIOC->CRH = (GPIOC->CRH & ~(0xF << (pin%8)*4) ) |  (mode | configuration << 2) << (pin%8)*4;
			break;
		case Peripheral_GPIOD:
			if(isLowerPort)
				GPIOD->CRL = (GPIOD->CRL & ~(0xF << (pin%8)*4) ) |  (mode | configuration << 2) << (pin%8)*4;
			else
				GPIOD->CRH = (GPIOD->CRH & ~(0xF << (pin%8)*4) ) |  (mode | configuration << 2) << (pin%8)*4;
			break;
		case Peripheral_GPIOE:
			if(isLowerPort)
				GPIOE->CRL = (GPIOE->CRL & ~(0xF << (pin%8)*4) ) |  (mode | configuration << 2) << (pin%8)*4;
			else
				GPIOE->CRH = (GPIOE->CRH & ~(0xF << (pin%8)*4) ) |  (mode | configuration << 2) << (pin%8)*4;
			break;
		case Peripheral_GPIOF:
			if(isLowerPort)
				GPIOF->CRL = (GPIOF->CRL & ~(0xF << (pin%8)*4) ) |  (mode | configuration << 2) << (pin%8)*4;
			else
				GPIOF->CRH = (GPIOF->CRH & ~(0xF << (pin%8)*4) ) |  (mode | configuration << 2) << (pin%8)*4;
			break;
		case Peripheral_GPIOG:
			if(isLowerPort)
				GPIOG->CRL = (GPIOG->CRL & ~(0xF << (pin%8)*4) ) |  (mode | configuration << 2) << (pin%8)*4;
			else
				GPIOG->CRH = (GPIOG->CRH & ~(0xF << (pin%8)*4) ) |  (mode | configuration << 2) << (pin%8)*4;
			break;
		
	}
}

void setGPIOBit(int port,int pin,bool value){
	if(value)
		setGPIOBitHigh(port,pin);
	else
		setGPIOBitLow (port,pin);
}

void setGPIOBitLow(int port,int pin){
	switch(port){
		case Peripheral_GPIOA:
			GPIOA->ODR &= ~(1 << pin);
			break;
		case Peripheral_GPIOB:
			GPIOB->ODR &= ~(1 << pin);
			break;
		case Peripheral_GPIOC:
			GPIOC->ODR &= ~(1 << pin);
		case Peripheral_GPIOD:
			GPIOD->ODR &= ~(1 << pin);
			break;
		case Peripheral_GPIOE:
			GPIOE->ODR &= ~(1 << pin);
			break;
		case Peripheral_GPIOF:
			GPIOF->ODR &= ~(1 << pin);
			break;
		case Peripheral_GPIOG:
			GPIOG->ODR &= ~(1 << pin);
			break;
	}
}
void setGPIOBitHigh(int port,int pin){
	switch(port){
		case Peripheral_GPIOA:
			GPIOA->ODR |=  (1 << pin);
			break;
		case Peripheral_GPIOB:
			GPIOB->ODR |=  (1 << pin);
			break;
		case Peripheral_GPIOC:
			GPIOC->ODR |=  (1 << pin);
			break;
		case Peripheral_GPIOD:
			GPIOD->ODR |=  (1 << pin);
			break;
		case Peripheral_GPIOE:
			GPIOE->ODR |=  (1 << pin);
			break;
		case Peripheral_GPIOF:
			GPIOF->ODR |=  (1 << pin);
			break;
		case Peripheral_GPIOG:
			GPIOG->ODR |=  (1 << pin);
			break;
		default:
			break;
	}
}

bool readGPIOBit(int port,int pin){
	switch(port){
		case Peripheral_GPIOA:
			return (GPIOA->IDR & (1 << pin))==0? 0:1;
		case Peripheral_GPIOB:
			return (GPIOB->IDR & (1 << pin))==0? 0:1;
		case Peripheral_GPIOC:
			return (GPIOC->IDR & (1 << pin))==0? 0:1;
		case Peripheral_GPIOD:
			return (GPIOD->IDR & (1 << pin))==0? 0:1;
		case Peripheral_GPIOE:
			return (GPIOE->IDR & (1 << pin))==0? 0:1;
		case Peripheral_GPIOF:
			return (GPIOF->IDR & (1 << pin))==0? 0:1;
		case Peripheral_GPIOG:
			return (GPIOG->IDR & (1 << pin))==0? 0:1;
		default:
			break;
	}
}


void USARTInitiate(int port, int baud){
	enablePeripheralClock(Peripheral_AFIO);
	switch(port){
		case Peripheral_USART1:
			enablePeripheralClock(Peripheral_USART1);
			enablePeripheralClock(Peripheral_GPIOA);
			configureGPIO(Peripheral_GPIOA, USART1_CONF_TX_PIN, GPIO_MODE_OUT_50MHZ, GPIO_CONF_OUT_ALT_PUSHPULL);
			configureGPIO(Peripheral_GPIOA, USART1_CONF_RX_PIN, GPIO_MODE_OUT_50MHZ, GPIO_CONF_OUT_ALT_PUSHPULL);
			USART1->CR1 |= USART_CONF_UE;
			USART1->BRR  = baud;
			USART1->CR1 |= USART_CONF_TE;
			while(!(USART1->SR & USART_STAT_TC));
			break;
		case Peripheral_USART2:
			enablePeripheralClock(Peripheral_USART2);
			enablePeripheralClock(Peripheral_GPIOA);
			configureGPIO(Peripheral_GPIOA, USART2_CONF_TX_PIN, GPIO_MODE_OUT_50MHZ, GPIO_CONF_OUT_ALT_PUSHPULL);
			configureGPIO(Peripheral_GPIOA, USART2_CONF_RX_PIN, GPIO_MODE_OUT_50MHZ, GPIO_CONF_OUT_ALT_PUSHPULL);
			USART2->CR1 |= USART_CONF_UE;
			USART2->BRR  = baud;
			USART2->CR1 |= USART_CONF_TE;
			while(!(USART2->SR & USART_STAT_TC));
			break;
		case Peripheral_USART3:
			enablePeripheralClock(Peripheral_USART3);
			enablePeripheralClock(Peripheral_GPIOB);
			configureGPIO(Peripheral_GPIOB, USART3_CONF_TX_PIN, GPIO_MODE_OUT_50MHZ, GPIO_CONF_OUT_ALT_PUSHPULL);
			configureGPIO(Peripheral_GPIOB, USART3_CONF_RX_PIN, GPIO_MODE_OUT_50MHZ, GPIO_CONF_OUT_ALT_PUSHPULL);
			USART3->CR1 |= USART_CONF_UE;
			USART3->BRR  = baud;
			USART3->CR1 |= USART_CONF_TE;
			while(!(USART3->SR & USART_STAT_TC));
			break;
		default:
			break;
	}
}

void USARTSendByte(int port, char value){
	
	switch(port){
		case Peripheral_USART1:
			USART1->DR = value;
			while(!(USART1->SR & USART_STAT_TC));
			break;
		case Peripheral_USART2:
			USART2->DR = value;
			while(!(USART2->SR & USART_STAT_TC));
			break;
		case Peripheral_USART3:
			USART3->DR = value;
			while(!(USART3->SR & USART_STAT_TC));
			break;
		default:
			break;
	}
}

void USARTSendStream(int port, char* data, int length){
	for(int i=0; i<length; i++){
		USARTSendByte(port, data[i]);
	}
}
void USARTSendString(int port, char* data){
	int i = 0;
	while(data[i]){
		USARTSendByte(port, data[i]);
		i++;
	}
}
