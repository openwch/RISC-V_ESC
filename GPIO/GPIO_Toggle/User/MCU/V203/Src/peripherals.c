/*
 * peripherals.c
 *
 * */
#include "peripherals.h"
#include "targets.h"
#include "serial_telemetry.h"


void initCorePeripherals(void)
{
  ALL_GPIO_Init( );   //gpio clock
  ALL_DMA_Init( );    //IC DMA and ADC DMA
  PWM_TIM1_Init( );   //6 channels PWM
  ZC_TIM4_Init( );    //zero cross timer
  ALL_COMP_Init( );   //ALL comparer
  COM_TIM3_Init( );   //
  TENKHz_SysTick_Init( );
  MX_TIM17_Init( );
  UN_TIM2_Init( );
  #ifdef USE_SERIAL_TELEMETRY
    telem_UART_Init();
  #endif
}

void initAfterJump(void)
{
    //don't need
}

void SystemClock_Config(void)
{
    //don't need
}




extern void EXTI2_IRQHandler(void)  __attribute__((interrupt("WCH-Interrupt-fast")));
void ALL_COMP_Init(void)
{

    GPIO_InitTypeDef        GPIO_InitStruct = {0};
    EXTI_InitTypeDef        EXTI_InitStructure = {0};

    GPIO_InitStruct.GPIO_Pin  = GPIO_Pin_5;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AIN;
    GPIO_Init(GPIOA, &GPIO_InitStruct);

    GPIO_InitStruct.GPIO_Pin  = GPIO_Pin_10|GPIO_Pin_11|GPIO_Pin_14|GPIO_Pin_15;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AIN;
    GPIO_Init(GPIOB, &GPIO_InitStruct);


    GPIO_InitStruct.GPIO_Pin  = GPIO_Pin_4|GPIO_Pin_3;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOA, &GPIO_InitStruct);

    GPIO_InitStruct.GPIO_Pin  = GPIO_Pin_2;              //中断汇入口
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOA, &GPIO_InitStruct);

    //1P0(PB15)  2P0(PB14) --> COM_BEMF   2N1(PA5)-->A_BEMF  2N0(PB10)-->B_BEMF 1N0(PB11)-->C_BEMF
    //2O1(PA4)  1O0(PA3)

    OPA->CR = 0x01;

    GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource2);
    EXTI_InitStructure.EXTI_Line = EXTI_Line2;
    EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
    EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising_Falling;
    EXTI_InitStructure.EXTI_LineCmd = DISABLE;
    EXTI_Init(&EXTI_InitStructure);
    EXTI_ClearITPendingBit(EXTI_Line2);

    SetVTFIRQ( (uint32_t)EXTI2_IRQHandler,EXTI2_IRQn,1,ENABLE  );  //过零比较中断设置为免表中断

    NVIC_SetPriority(EXTI2_IRQn, 0x0);
    NVIC_EnableIRQ(EXTI2_IRQn);

}



void MX_IWDG_Init(void)
{
  IWDG->CTLR = 0x5555;
  IWDG->PSCR = IWDG_Prescaler_32;
  IWDG->RLDR = 4000;
  IWDG_ReloadCounter( );
  IWDG_Enable( );
}


void PWM_TIM1_Init(void)  //PWM
{
    TIM_TimeBaseInitTypeDef TIM_InitStruct = {0};
    TIM_OCInitTypeDef       TIM_OC_InitStruct = {0};
    TIM_BDTRInitTypeDef     TIM_BDTRInitStruct = {0};
    GPIO_InitTypeDef        GPIO_InitStruct = {0};

    RCC_APB2PeriphClockCmd( RCC_APB2Periph_TIM1|RCC_APB2Periph_AFIO, ENABLE );
    GPIO_PinRemapConfig(GPIO_PartialRemap_TIM1, ENABLE);


    TIM_InitStruct.TIM_Period = 2000-1;
    TIM_InitStruct.TIM_Prescaler = 0;
    TIM_InitStruct.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_InitStruct.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseInit( TIM1, &TIM_InitStruct);

    TIM_ARRPreloadConfig( TIM1, ENABLE );



    TIM_OC1PreloadConfig( TIM1, TIM_OCPreload_Enable );
#ifdef USE_SWAPPED_OUPUT
    TIM_OC_InitStruct.TIM_OCMode = TIM_OCMode_PWM2;
#else
    TIM_OC_InitStruct.TIM_OCMode = TIM_OCMode_PWM1;
#endif
    TIM_OC_InitStruct.TIM_OutputState  = TIM_OutputState_Disable;
    TIM_OC_InitStruct.TIM_OutputNState = TIM_OutputNState_Disable;
    TIM_OC_InitStruct.TIM_Pulse = 0;
#ifdef USE_INVERTED_HIGH
  TIM_OC_InitStruct.TIM_OCPolarity = TIM_OCPolarity_Low;
  TIM_OC_InitStruct.TIM_OCIdleState = TIM_OCIdleState_Set;
#else
  TIM_OC_InitStruct.TIM_OCPolarity = TIM_OCPolarity_High;
  TIM_OC_InitStruct.TIM_OCIdleState = TIM_OCIdleState_Reset;
#endif

#ifdef USE_INVERTED_LOW
  TIM_OC_InitStruct.TIM_OCNPolarity = TIM_OCNPolarity_High;
  TIM_OC_InitStruct.TIM_OCNIdleState = TIM_OCNIdleState_Reset;
#else
  TIM_OC_InitStruct.TIM_OCNPolarity = TIM_OCNPolarity_High;
  TIM_OC_InitStruct.TIM_OCNIdleState = TIM_OCNIdleState_Reset;
#endif
  TIM_OC1Init( TIM1, &TIM_OC_InitStruct );
  TIM_OC1FastConfig(TIM1,TIM_OCFast_Disable);

  TIM_OC2PreloadConfig( TIM1, TIM_OCPreload_Enable );
  TIM_OC_InitStruct.TIM_OutputState  = TIM_OutputState_Disable;
  TIM_OC_InitStruct.TIM_OutputNState = TIM_OutputNState_Disable;
  TIM_OC2Init( TIM1, &TIM_OC_InitStruct );
  TIM_OC2FastConfig(TIM1,TIM_OCFast_Disable);

  TIM_OC3PreloadConfig( TIM1, TIM_OCPreload_Enable );
  TIM_OC_InitStruct.TIM_OutputState  = TIM_OutputState_Disable;
  TIM_OC_InitStruct.TIM_OutputNState = TIM_OutputNState_Disable;
  TIM_OC3Init( TIM1, &TIM_OC_InitStruct );
  TIM_OC3FastConfig(TIM1,TIM_OCFast_Disable);

  TIM_OC4PreloadConfig( TIM1, TIM_OCPreload_Enable );
  TIM_OC_InitStruct.TIM_OutputState  = TIM_OutputState_Disable;
  TIM_OC_InitStruct.TIM_OutputNState = TIM_OutputNState_Disable;
  TIM_OC4Init( TIM1, &TIM_OC_InitStruct );
  TIM_OC4FastConfig(TIM1,TIM_OCFast_Disable);

  TIM_BDTRInitStruct.TIM_OSSRState = TIM_OSSRState_Disable;
  TIM_BDTRInitStruct.TIM_OSSIState = TIM_OSSIState_Disable;
  TIM_BDTRInitStruct.TIM_LOCKLevel = TIM_LOCKLevel_OFF;
  TIM_BDTRInitStruct.TIM_DeadTime  = DEAD_TIME;
  TIM_BDTRInitStruct.TIM_Break = TIM_Break_Disable;
  TIM_BDTRInitStruct.TIM_BreakPolarity = TIM_BreakPolarity_High;
  TIM_BDTRInitStruct.TIM_AutomaticOutput = TIM_AutomaticOutput_Disable;
  TIM_BDTRConfig(TIM1,&TIM_BDTRInitStruct);

  /*
   * T1CH1---PA8
   * T1CH2---PA9
   * T1CH3---PA10
   * T1CH1N--PA7
   * T1CH2N--PB0
   * T1CH3N--PB1
   * */
  GPIO_InitStruct.GPIO_Pin = PHASE_A_GPIO_LOW;
  GPIO_InitStruct.GPIO_Mode= GPIO_Mode_AF_PP ;
  GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(PHASE_A_GPIO_PORT_LOW, &GPIO_InitStruct);

  GPIO_InitStruct.GPIO_Pin = PHASE_B_GPIO_LOW;
  GPIO_InitStruct.GPIO_Mode= GPIO_Mode_AF_PP ;
  GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(PHASE_B_GPIO_PORT_LOW, &GPIO_InitStruct);

  GPIO_InitStruct.GPIO_Pin = PHASE_C_GPIO_LOW;
  GPIO_InitStruct.GPIO_Mode= GPIO_Mode_AF_PP ;
  GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(PHASE_C_GPIO_PORT_LOW, &GPIO_InitStruct);

  GPIO_InitStruct.GPIO_Pin = PHASE_A_GPIO_HIGH;
  GPIO_InitStruct.GPIO_Mode= GPIO_Mode_AF_PP ;
  GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(PHASE_A_GPIO_PORT_HIGH, &GPIO_InitStruct);

  GPIO_InitStruct.GPIO_Pin = PHASE_B_GPIO_HIGH;
  GPIO_InitStruct.GPIO_Mode= GPIO_Mode_AF_PP ;
  GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(PHASE_B_GPIO_PORT_HIGH, &GPIO_InitStruct);

  GPIO_InitStruct.GPIO_Pin = PHASE_C_GPIO_HIGH;
  GPIO_InitStruct.GPIO_Mode= GPIO_Mode_AF_PP ;
  GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(PHASE_C_GPIO_PORT_HIGH, &GPIO_InitStruct);
}



void ZC_TIM4_Init(void) //zctimer 0.5us
{
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE );
    TIM4->PSC = 23;
    TIM4->ATRLR = 0xFFFF;
}



void TENKHz_SysTick_Init(void)  //10Khz
{
    SysTick->CTLR = 0;
    SysTick->SR   = 0;
    SysTick->CNT  = 0;
    SysTick->CMP  = SystemCoreClock / 10000;
    SysTick->CTLR = 0xF;
    NVIC_SetPriority(SysTicK_IRQn, 0xE0);
    NVIC_EnableIRQ(SysTicK_IRQn);
}


void COM_TIM3_Init(void)  //comtimer 0.5us
{
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE );
    TIM3->PSC  = 23;
    TIM3->ATRLR=4000;
    NVIC_SetPriority(TIM3_IRQn, 0);
    NVIC_EnableIRQ(TIM3_IRQn);
}


void MX_TIM16_Init(void)
{
    //don't need
}


void MX_TIM17_Init(void) //1us
{
    //don't need
}

extern void DMA1_Channel5_IRQHandler(void)  __attribute__((interrupt("WCH-Interrupt-fast")));
void ALL_DMA_Init(void)
{

    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);

    NVIC_SetPriority(DMA1_Channel5_IRQn, 0xC0);  //和ADC  DMA同一个抢占优先级
    NVIC_EnableIRQ(DMA1_Channel5_IRQn);
    SetVTFIRQ( (uint32_t)DMA1_Channel5_IRQHandler,DMA1_Channel5_IRQn,0,ENABLE);


    NVIC_SetPriority(DMA1_Channel1_IRQn, 0xC0); //for ADC
    NVIC_EnableIRQ(DMA1_Channel1_IRQn);
}

void ALL_GPIO_Init(void)
{
    /* GPIO Ports Clock Enable */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO | RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB, ENABLE);
    /**/
  #ifdef USE_ALKAS_DEBUG_LED
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_15;
    GPIO_InitStruct.GPIO_Mode= GPIO_Mode_Out_PP ;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStruct);
  #endif

}


void UN_TIM2_Init(void)  //输入捕获
{
  GPIO_InitTypeDef         GPIO_InitStruct = {0};
  TIM_TimeBaseInitTypeDef  TIM_InitStruct = {0};
  TIM_ICInitTypeDef        TIM_ICInitStructure = {0};

  /* Peripheral clock enable */
#ifdef USE_TIMER_4_CHANNEL_3
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4 , ENABLE );
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE );
  /*
   *PB8   ------> TIM4_CH3
  */
  GPIO_InitStruct.GPIO_Pin   = GPIO_Pin_8;
  GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_IN_FLOATING;
  GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStruct);
#endif

#ifdef USE_TIMER_4_CHANNEL_3
  //enable core Interrupt  and set priority as the highest
  NVIC_SetPriority(TIM4_IRQn, 0x20);
  NVIC_EnableIRQ(TIM4_IRQn);
#endif

#ifdef USE_TIMER_2_CHANNEL_1
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2 , ENABLE );
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE );
  /*
   *PA0   ------> TIM2_CH1
  */
  GPIO_InitStruct.GPIO_Pin   = GPIO_Pin_0;
  GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_IN_FLOATING;
  GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA, &GPIO_InitStruct);
#endif

#ifdef USE_TIMER_2_CHANNEL_1
  //enable core Interrupt  and set priority as the highest
  NVIC_SetPriority(TIM2_IRQn, 0x20);
  NVIC_EnableIRQ(TIM2_IRQn);
#endif


  TIM_InitStruct.TIM_Period = 0xFFFF;
  TIM_InitStruct.TIM_Prescaler = 0;
  TIM_InitStruct.TIM_ClockDivision = TIM_CKD_DIV1;
  TIM_InitStruct.TIM_CounterMode = TIM_CounterMode_Up;
  TIM_TimeBaseInit( TIM2, &TIM_InitStruct);
  TIM_ARRPreloadConfig( TIM2, ENABLE );
  TIM_SelectOutputTrigger(TIM2,TIM_TRGOSource_Reset);

  TIM_ICInitStructure.TIM_Channel = TIM_Channel_1;
  TIM_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;
  TIM_ICInitStructure.TIM_ICFilter = 0x00;
  TIM_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising;       //从上升沿开始
  TIM_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI;
  TIM_ICInit(TIM2, &TIM_ICInitStructure);

  TIM_DMACmd(TIM2, TIM_DMA_CC1, ENABLE);

}

#ifdef USE_RGB_LED              // has 3 color led
void LED_GPIO_init()
{
      GPIO_InitTypeDef GPIO_InitStruct = {0};
      /* GPIO Ports Clock Enable */
      LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOB);

      LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_8);
      LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);
      LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_3);

      GPIO_InitStruct.Pin = LL_GPIO_PIN_8;
      GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
      GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_LOW;
      GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
      GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
      LL_GPIO_Init(GPIOB, &GPIO_InitStruct);

      GPIO_InitStruct.Pin = LL_GPIO_PIN_5;
      GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
      GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_LOW;
      GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
      GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
      LL_GPIO_Init(GPIOB, &GPIO_InitStruct);

      GPIO_InitStruct.Pin = LL_GPIO_PIN_3;
      GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
      GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_LOW;
      GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
      GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
      LL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

#endif


