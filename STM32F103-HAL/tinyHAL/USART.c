#include "USART.h"

void USARTInitiate(int port, int baud, int mode){
	enablePeripheralClock(Peripheral_AFIO);
	switch(port){
		case Peripheral_USART1:
			enablePeripheralClock(Peripheral_USART1);
			enablePeripheralClock(Peripheral_GPIOA);
			if(mode == USART_MODE_RECEIVE){
				configureGPIO(Peripheral_GPIOA, USART1_CONF_RX_PIN, GPIO_MODE_OUT_50MHZ, GPIO_CONF_OUT_ALT_PUSHPULL);
				USART1->CR1 |= USART_CONF_RE;
			}	
			if(mode == USART_MODE_TRANSMIT){
				configureGPIO(Peripheral_GPIOA, USART1_CONF_TX_PIN, GPIO_MODE_OUT_50MHZ, GPIO_CONF_OUT_ALT_PUSHPULL);
				USART1->CR1 |= USART_CONF_TE;
			}
			USART1->BRR  = baud;
			USART1->CR1 |= USART_CONF_UE;
			
			while(!(USART1->SR & USART_STAT_TC));
			break;
		case Peripheral_USART2:
			enablePeripheralClock(Peripheral_USART2);
			enablePeripheralClock(Peripheral_GPIOA);
			if(mode == USART_MODE_RECEIVE){
				configureGPIO(Peripheral_GPIOA, USART2_CONF_RX_PIN, GPIO_MODE_OUT_50MHZ, GPIO_CONF_OUT_ALT_PUSHPULL);
				USART2->CR1 |= USART_CONF_RE;
			}	
			if(mode == USART_MODE_TRANSMIT){
				configureGPIO(Peripheral_GPIOA, USART2_CONF_TX_PIN, GPIO_MODE_OUT_50MHZ, GPIO_CONF_OUT_ALT_PUSHPULL);
				USART2->CR1 |= USART_CONF_TE;
			}
			USART2->BRR  = baud;
			USART2->CR1 |= USART_CONF_UE;
			
			while(!(USART2->SR & USART_STAT_TC));
			break;
		case Peripheral_USART3:
			enablePeripheralClock(Peripheral_USART3);
			enablePeripheralClock(Peripheral_GPIOB);
			if(mode == USART_MODE_RECEIVE){
				configureGPIO(Peripheral_GPIOB, USART3_CONF_RX_PIN, GPIO_MODE_OUT_50MHZ, GPIO_CONF_OUT_ALT_PUSHPULL);
				USART3->CR1 |= USART_CONF_RE;
			}	
			if(mode == USART_MODE_TRANSMIT){
				configureGPIO(Peripheral_GPIOB, USART3_CONF_TX_PIN, GPIO_MODE_OUT_50MHZ, GPIO_CONF_OUT_ALT_PUSHPULL);
				USART3->CR1 |= USART_CONF_TE;
			}
			USART3->BRR  = baud;
			USART3->CR1 |= USART_CONF_UE;
			
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
char USARTReadByte(int port){
	switch(port){
		case Peripheral_USART1:
			while(!(USART1->SR & USART_STAT_RXNE));
			return (USART3->DR & 0xFF);
		case Peripheral_USART2:
			while(!(USART2->SR & USART_STAT_RXNE));
			return (USART3->DR & 0xFF);
		case Peripheral_USART3:
			while(!(USART3->SR & USART_STAT_RXNE));
			return (USART3->DR & 0xFF);
		default:
			break;
	}
	
	
}
