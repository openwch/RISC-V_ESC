/*
 * peripherals.h
 *
 *  Created on: Sep. 26, 2020
 *      Author: Alka
 */

#ifndef PERIPHERALS_H_
#define PERIPHERALS_H_

#include "main.h"

void initAfterJump(void);
void initCorePeripherals(void);
void SystemClock_Config(void);
void ALL_GPIO_Init(void);
void ALL_DMA_Init(void);
//static void MX_ADC_Init(void);
void ALL_COMP_Init(void);
void PWM_TIM1_Init(void);
void ZC_TIM4_Init(void);
void MX_IWDG_Init(void);
void MX_TIM16_Init(void);
void COM_TIM3_Init(void);
void TENKHz_SysTick_Init(void);
void MX_TIM17_Init(void);
void UN_TIM2_Init(void);
void LED_GPIO_init(void);







#endif /* PERIPHERALS_H_ */







