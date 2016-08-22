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
			
//#define TEST1
#define TEST2

int gpioTest(void)
{
	  GPIO_InitTypeDef  GPIO_InitStructure;

	  /* GPIOA Peripheral clock enable */
	  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

	  /* Configure PA5 in output pushpull mode */
	  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
	  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	  GPIO_Init(GPIOA, &GPIO_InitStructure);

	  while (1)
	  {
#if defined(TEST1)
	    /* Set PG6 and PG8 */
	    GPIOA->BSRRL = GPIO_Pin_5;
	    /* Reset PG6 and PG8 */
	    GPIOA->BSRRH = GPIO_Pin_5;

	    /* Set PG6 and PG8 */
	    GPIOA->BSRRL = GPIO_Pin_5;
	    /* Reset PG6 and PG8 */
	    GPIOA->BSRRH = GPIO_Pin_5;

	    /* Set PG6 and PG8 */
	    GPIOA->BSRRL = GPIO_Pin_5;
	    /* Reset PG6 and PG8 */
	    GPIOA->BSRRH = GPIO_Pin_5;

	    /* Set PG6 and PG8 */
	    GPIOA->BSRRL = GPIO_Pin_5;
	    /* Reset PG6 and PG8 */
	    GPIOA->BSRRH = GPIO_Pin_5;

	    /* Set PG6 and PG8 */
	    GPIOA->BSRRL = GPIO_Pin_5;
	    /* Reset PG6 and PG8 */
	    GPIOA->BSRRH = GPIO_Pin_5;

	    /* Set PG6 and PG8 */
	    GPIOA->BSRRL = GPIO_Pin_5;
	    /* Reset PG6 and PG8 */
	    GPIOA->BSRRH = GPIO_Pin_5;

	    /* Set PG6 and PG8 */
	    GPIOA->BSRRL = GPIO_Pin_5;
	    /* Reset PG6 and PG8 */
	    GPIOA->BSRRH = GPIO_Pin_5;

	    /* Set PG6 and PG8 */
	    GPIOA->BSRRL = GPIO_Pin_5;
	    /* Reset PG6 and PG8 */
	    GPIOA->BSRRH = GPIO_Pin_5;

	    /* Set PG6 and PG8 */
	    GPIOA->BSRRL = GPIO_Pin_5;
	    /* Reset PG6 and PG8 */
	    GPIOA->BSRRH = GPIO_Pin_5;

	    /* Set PG6 and PG8 */
	    GPIOA->BSRRL = GPIO_Pin_5;
	    /* Reset PG6 and PG8 */
	    GPIOA->BSRRH = GPIO_Pin_5;
#elif defined(TEST2)
	    GPIO_ToggleBits(GPIOA, GPIO_Pin_5);
	    EnableTiming();
	    TimingDelay(180000000); /* 1 sec */
#endif
	  }

}
