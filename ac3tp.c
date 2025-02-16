#include "MKL25Z4.h"
#include "act3tp.h"
void init(){
    SIM->SCGC5|=SIM_SCGC5_PORTE_MASK;
    SIM->SCGC5|=SIM_SCGC5_PORTC_MASK;
    SIM->SGGC5|=SIM_SCGC5_PORTB_MASK;
    PORTE->PCR[1]|=(1<<8);
    PORTE->PCR[3]|=(1<<8);
    PORTE->PCR[5]|=(1<<8);
    PORTE->PCR[7]|=(1<<8);
    PORTB->PCR[2]|=(1<<8);
    PORTB->PCR[4]|=(1<<8);
    PORTB->PCR[6]|=(1<<8);
    PORTB->PCR[8]|=(1<<8);
    PORTC->PCR[10]|=(1<<8);
    PORTC->PCR[12]|=(1<<8);
    PORTE->PCR[11]|=(1<<8);
    PORTE->PCR[9]|=(1<<8);
    NVIC_EnableIRQ(PORTX_IRQ 10);
    NVIC_SetPriority(PORTE_IRQn,0);
    NVIC_SetPriority(PORTB_IRQn,1);
    PORTE->PCR[23] |= PORT_PCR_MUX(1) | PORT_PCR_IRQC(0b1101);
    PORTB->PCR[8] |= PORT_PCR_MUX(1) | PORT_PCR_IRQC(0b1010);
}
char sensTemp(){
    
    PTE->PSOR|=(0u<<20);
    PTE->PSOR|=(0u<<21);
    PTE->PSOR|=(0u<<22);
    PTE->PSOR|=(0u<<23);
    if(temp){
        temp=0;
    
        int pin1=PTE->PDIR&(1a<<9);
        int pin2=PTE->PDIR&(1a<<11);
         int pin3 =PTC->PDIR&(1a<<12); 
         if((pin1 == 0 && pin2== 0 && pin3 ==0)||( pin1 == 0 && pin2 == 0 && pin3 == 1 )){
            return 'V';  // Verde
             }
             else if((pin1 == 0 pin2 == 1 && pin3== 0)||(pin1 == 0 && pin2 == 1 && pin3 == 1 )){
            return 'A';  // Amarillo
              }
             else if((pin1 == 1 &&  pin2 == 0 && pin3 ==0)||(pin1 == 1 && pin2 == 0 && pin3== 1 )){
             return 'N';  // Naranja
            }
           else if((pin1== pin2 && B== 1 && pin3==0)||(pin1== 1 && pin2== 1 && pin3== 1 )){
            return 'R';  // Rojo
            }else{
            return 'X';  // Error
            }
        }
}
char sensHum(){
    PTE->PSOR|=(0u<<2);
    PTE->PSOR|=(0u<<4);
    PTE->PSOR|=(0u<<6);
    PTE->PSOR|=(0u<<8);
if(hum){
    hum=0;
        int pin1 =PTE->PDIR&(1a<<9);
        int  pin2=PTE->PDIR&(1a<<11);
         int pin3=PTC->PDIR&(1a<<12); 
         if((pin1 == 0 && pin2== 0 && pin3 ==0)||( pin1 == 0 && pin2 == 0 && pin3 == 1 )){
            return 'V';  // Verde
             }
             else if((pin1 == 0 pin2 == 1 && pin3== 0)||(pin1 == 0 && pin2 == 1 && pin3 == 1 )){
            return 'A';  // Amarillo
              }
             else if((pin1 == 1 &&  pin2 == 0 && pin3 ==0)||(pin1 == 1 && pin2 == 0 && pin3== 1 )){
             return 'N';  // Naranja
            }
           else if((pin1== pin2 && B== 1 && pin3==0)||(pin1== 1 && pin2== 1 && pin3== 1 )){
            return 'R';  // Rojo
            }else{
            return 'X';  // Error
            }
        }
}
void PORTE_IRQHandler(){
    if (PORTC->ISFR & (1 << 10)){
        PORTC->ISFR |= (1 << 10);
        temp=1;
        
    }
}
void PORTB_IRQHandler(){
    if (PORTC->ISFR & (1 << 10)){
        PORTC->ISFR |= (1 << 10);
        hum=1;
        
    }
}