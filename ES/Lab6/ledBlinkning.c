/*Interfacing LED to ARM*/
#include<lpc17xx.h>
void delay_ms(unsigned int ms){
  unsigned int i,j;
  for(i=0;i<ms;i++)
    for(j=0;j<50000;j++);
}
int main(){
  SystemInit();
  LPC_PINCON->PINSEL4=0x000000;
  LPC_GPIO->FIODIR=0xFFFFFFFF;
  while(1){
    LPC_GPIO2->FIOSET=0xFFFFFFFF;
    delay_ms(100);
    LPC_GPIO2->FIOCLR=0xFFFFFFFF;
    delay_ms(100);
  }
}
