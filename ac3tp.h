#ifndef ac3tp_h
#define ac3tp_h
#include temperatu.h
void init();
char sensTemp();
char sensHum();
void PORTE_IRQHandler();
void PORTB_IRQHandler();
#endif