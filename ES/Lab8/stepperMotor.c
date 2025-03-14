#include<LPC17xx.h>
void clock_wise(void);
void anti_clock_wise(void);
unsigned long int var1, var2;
unsigned int i=0,j=0,k=0;
int main (void)
{
  SystemInit();
  SystemCoreClockUpdate();
  LPC_PINCON->PINSEL0=0XFFFF00FF;
  LPC_GPIO0->FIODIR=0X000000F0;
  while(1)
    {
      for(j=0;j<50;j++)
        clock_wise();
      for(k=0;k<65000;k++);
      for(j=0;j<50;j++)
        anti_clock_wise();
      for(k=0;k<65000;k++);      
    }
}
//tbc void clock_wise funct
