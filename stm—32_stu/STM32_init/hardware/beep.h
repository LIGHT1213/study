#ifndef __BEEP_H
#define __BEEP_H

#define BEEPER_PIN                   GPIO_Pin_6
#define GPIO_BEEPER                  GPIOF
#define BUZZER_GPIO_CLK              RCC_AHB1Periph_GPIOF	

void Buzzerinit(void);

#endif
