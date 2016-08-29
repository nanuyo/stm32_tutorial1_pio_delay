#include "stm32f4xx.h"
#include "led.h"
#include "timer.h"


void HJ_TimerInit(void)
{
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);

    TIM_TimeBaseInitTypeDef timerInitStructure;

    timerInitStructure.TIM_Prescaler = 40000;
    timerInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
    timerInitStructure.TIM_Period = 500;
    timerInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    timerInitStructure.TIM_RepetitionCounter = 0;
    TIM_TimeBaseInit(TIM2, &timerInitStructure);
    TIM_Cmd(TIM2, ENABLE);
}

void HJ_TimerInterruptInit(void)
{
    TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
}


void HJ_TimerInterruptEnable(void)
{
    NVIC_InitTypeDef nvicStructure;

    nvicStructure.NVIC_IRQChannel = TIM2_IRQn;
	nvicStructure.NVIC_IRQChannelPreemptionPriority = 0;
	nvicStructure.NVIC_IRQChannelSubPriority = 1;
	nvicStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&nvicStructure);
}

void HJ_TimerInitLEDforPWM(void)
{
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

    GPIO_InitTypeDef gpioStructure;
    gpioStructure.GPIO_Pin = GPIO_Pin_5;
    gpioStructure.GPIO_Mode = GPIO_Mode_AF;
    gpioStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &gpioStructure);
}

void HJ_TimerPWMChannelInit(void)
{
    TIM_OCInitTypeDef outputChannelInit = {0,};
    outputChannelInit.TIM_OCMode = TIM_OCMode_PWM1;
    outputChannelInit.TIM_Pulse = 400;
    outputChannelInit.TIM_OutputState = TIM_OutputState_Enable;
    outputChannelInit.TIM_OCPolarity = TIM_OCPolarity_High;

    TIM_OC1Init(TIM2, &outputChannelInit);
    TIM_OC1PreloadConfig(TIM2, TIM_OCPreload_Enable);

    GPIO_PinAFConfig(GPIOA, GPIO_PinSource5, GPIO_AF_TIM2);
}

extern void TIM2_IRQHandler();
void TIM2_IRQHandler()
{
    if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET)
    {
        TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
        GPIO_ToggleBits(GPIOA, GPIO_Pin_5);
    }
}

void HJ_TimerTest(void)
{
	HJ_LedInit();
    HJ_TimerInit();

    for (;;)
    {
        int timerValue = TIM_GetCounter(TIM2);
        if (timerValue == 400)
            GPIO_WriteBit(GPIOA, GPIO_Pin_5, Bit_SET);
        else if (timerValue == 500)
            GPIO_WriteBit(GPIOA, GPIO_Pin_5, Bit_RESET);
    }
}

void HJ_TimerInterruptTest(void)
{
    HJ_LedInit();
    HJ_TimerInit();
    HJ_TimerInterruptInit();

    for (;;)
    {
        if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET)
        {
            TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
            GPIO_ToggleBits(GPIOA, GPIO_Pin_5);
        }
    }
}

void HJ_TimerInterruptHandlerTest(void)
{
    HJ_LedInit();
    HJ_TimerInit();
    HJ_TimerInterruptInit();
    HJ_TimerInterruptEnable();
}

void HJ_TimerPWMTest(void)
{
    HJ_TimerInitLEDforPWM();
    HJ_TimerInit();
    HJ_TimerPWMChannelInit();
}
