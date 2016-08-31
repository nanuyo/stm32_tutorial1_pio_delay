/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/



#include "stm32f4xx.h"
#include "led.h"
#include "timer.h"

int main(void)
{

	HJ_LedToggleTest();
	//HJ_TimerTest();
	//HJ_TimerInterruptTest();
	//HJ_TimerInterruptHandlerTest();
	//HJ_TimerPWMTest();

	for(;;);
}
