#include "stm32f103_hal_core.h"

void enableIRQ(int irq, int priority);
void disableIRQ(int irq);
void setPendingIRQ(int irq);
void clearPendingIRQ(int irq);
void enableInterrupts();
void disableInterrupts();