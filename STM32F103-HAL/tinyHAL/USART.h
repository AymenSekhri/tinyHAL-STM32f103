#include "stm32f103_hal_core.h"

#define USART1_CONF_TX_PIN		9		//PA9
#define USART1_CONF_RX_PIN		10		//PA10

#define USART2_CONF_TX_PIN		2		//PA2
#define USART2_CONF_RX_PIN		3		//PA3

#define USART3_CONF_TX_PIN		10		//PB10
#define USART3_CONF_RX_PIN		11		//PB11

#define USART_CONF_UE			(1<<13)
#define USART_CONF_TE			(1<<3)
#define USART_CONF_RE			(1<<2)

#define USART_STAT_TC			(1<<6)
#define USART_STAT_RXNE			(1<<5)

#define USART_MODE_RECEIVE				1
#define USART_MODE_TRANSMIT				2


void USARTInitiate(int port, int baud, int mode);
void USARTSendByte(int port, char value);
void USARTSendStream(int port, char* data, int length);
void USARTSendString(int port, char* data);
char USARTReadByte(int port);
