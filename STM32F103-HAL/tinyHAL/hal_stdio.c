#include "hal_stdio.h"

struct __FILE{int handle;};
FILE __stdin  = {0};
FILE __stdout = {0};
FILE __stderr = {0};

int fputc(int c, FILE *f) {
	USARTSendByte(Peripheral_USART1, (char)c);
	return c;
}

int fgetc(FILE *f) {
	return USARTReadByte(Peripheral_USART1);
}

int max(int a, int b){
	if (a>b)
		return a;
	else
		return b;
}