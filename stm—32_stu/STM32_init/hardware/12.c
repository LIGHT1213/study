#include "led.h"
#include "stm32f4xx.h"

void LEDinit(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_AHB1PeriphClockCmd(RCC_GPIO_LED, ENABLE);
	GPIO_InitStructure.GPIO_Pin = DS1_PIN|DS2_PIN|DS3_PIN|DS4_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;     
  GPIO_Init(GPIO_LED, &GPIO_InitStructure);
  GPIO_SetBits(GPIO_LED,DS1_PIN|DS2_PIN|DS3_PIN|DS4_PIN);  
}
