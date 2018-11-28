#include "beep.h"
#include "stm32f4xx.h"
void Buzzerinit(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
  RCC_AHB1PeriphClockCmd(BUZZER_GPIO_CLK, ENABLE);
  GPIO_InitStructure.GPIO_Pin = BEEPER_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL; 
  GPIO_Init(GPIO_BEEPER, &GPIO_InitStructure);
	GPIO_SetBits(GPIO_BEEPER,BEEPER_PIN);
}
