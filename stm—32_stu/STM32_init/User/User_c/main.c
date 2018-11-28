#include "stm32f4xx.h"
#include <stdio.h>
#include "led.h"
#include "beep.h"
#include "key.h"
#include "delay.h"
#define my
int main(void)
{
	u8 key=0;
	Buzzerinit();
	keyinit();
	LEDinit();
	delay_init(168);
	while(1)
	{
		key=keyscan(0);
		if(key)
		{
			switch(key)
			{
		   case KEY1_Press:
		   GPIO_ResetBits(GPIO_BEEPER,BEEPER_PIN);
			 delay_ms(1000);
			 GPIO_SetBits(GPIO_BEEPER,BEEPER_PIN);
			 break;
       case KEY2_Press:
			 GPIO_ResetBits(GPIO_BEEPER,BEEPER_PIN);
			 delay_ms(2000);
			 GPIO_SetBits(GPIO_BEEPER,BEEPER_PIN);
			 delay_ms(1000);
			 GPIO_ResetBits(GPIO_BEEPER,BEEPER_PIN);
			 delay_ms(3000);
			 GPIO_SetBits(GPIO_BEEPER,BEEPER_PIN);
       break;	
			 case KEY3_Press:
       GPIO_ResetBits(GPIO_LED,DS1_PIN|DS2_PIN);
			 delay_ms(1000);
			 GPIO_SetBits(GPIO_LED,DS1_PIN|DS2_PIN);
			 delay_ms(1000);
			 GPIO_ResetBits(GPIO_LED,DS3_PIN|DS4_PIN);
			 delay_ms(1000);
			 GPIO_SetBits(GPIO_LED,DS3_PIN|DS4_PIN);
			 break;
       case KEY4_Press:
			 GPIO_ResetBits(GPIO_LED,DS1_PIN|DS2_PIN|DS3_PIN|DS4_PIN);
			 delay_ms(1000);
			 GPIO_SetBits(GPIO_LED,DS1_PIN|DS2_PIN|DS3_PIN|DS4_PIN);			 
       break;			        				 
			}
		}
	}
}
