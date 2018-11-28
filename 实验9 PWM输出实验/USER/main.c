#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "pwm.h"
#define official
int main(void)
{ 
	int a=0;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	delay_init(168); 
	uart_init(9600);
 	TIM14_PWM_Init(500-1,84-1);	
   while(1)
	{
		if(a<=300)
			a++;
		else 
			a=0;
 
		TIM_SetCompare1(TIM14,a);
	}
}
