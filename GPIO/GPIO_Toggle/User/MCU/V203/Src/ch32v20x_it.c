/********************************** (C) COPYRIGHT *******************************
 * File Name          : ch32v20x_it.c
 * Author             : WCH
 * Version            : V1.0.0
 * Date               : 2021/06/06
 * Description        : Main Interrupt Service Routines.
*********************************************************************************
* Copyright (c) 2021 Nanjing Qinheng Microelectronics Co., Ltd.
* Attention: This software (modified or not) and binary are used for 
* microcontroller manufactured by Nanjing Qinheng Microelectronics.
*******************************************************************************/
#include "main.h"
#include "ch32v20x_it.h"
#include "targets.h"
#include "ADC.h"


extern void transfercomplete();
extern void PeriodElapsedCallback();
extern void interruptRoutine();
extern void doPWMChanges();
extern void tenKhzRoutine();
extern void sendDshotDma();
extern void receiveDshotDma();

extern char send_telemetry;
extern char telemetry_done;
extern char servoPwm;
extern char dshot;
extern char inputSet;



void NMI_Handler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
void HardFault_Handler(void) __attribute__((interrupt("WCH-Interrupt-fast")));



void DMA1_Channel1_IRQHandler(void)  __attribute__((interrupt("WCH-Interrupt-fast")));
void DMA1_Channel5_IRQHandler(void)  __attribute__((interrupt("WCH-Interrupt-fast")));
void SysTick_Handler(void)  __attribute__((interrupt("WCH-Interrupt-fast")));

void EXTI2_IRQHandler(void)  __attribute__((interrupt("WCH-Interrupt-fast")));
void DMA1_Channel4_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));


void TIM3_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));

/*********************************************************************
 * @fn      NMI_Handler
 *
 * @brief   This function handles NMI exception.
 *
 * @return  none
 */
void NMI_Handler(void)
{
}

/*********************************************************************
 * @fn      HardFault_Handler
 *
 * @brief   This function handles Hard Fault exception.
 *
 * @return  none
 */
void HardFault_Handler(void)
{
//    printf("mcause:%0x\r\n",__get_MCAUSE());
//    printf("mtval:%0x\r\n",__get_MTVAL());
//    printf("mepc:%0x\r\n",__get_MEPC());

    GPIOA->BCR   = GPIO_Pin_6;
    GPIOA->CFGLR &= ~(0xf<<24);
    GPIOA->CFGLR |= (0x3<<24);

    while (1)
    {
    }
}




void DMA1_Channel1_IRQHandler(void)
{
    if(DMA_GetITStatus(DMA1_IT_TC1))
    {
        DMA_ClearFlag(DMA1_IT_TC1|DMA1_IT_HT1);
        ADC_DMA_Callback();
    }
    /* Check whether DMA transfer error caused the DMA interruption */
    if(DMA_GetITStatus(DMA1_IT_TE1))
    {
        DMA_ClearFlag(DMA1_IT_TE1);
    }

}

void DMA1_Channel5_IRQHandler(void)
{
    if(DMA1->INTFR & DMA1_IT_HT5) //´«Êä¹ý°ë,ÇÐ»»±ßÑØ
    {
        if(servoPwm)
        {
            IC_TIMER_REGISTER->CCER = 0x03;  //ÇÐ»»ÎªÏÂ½µÑØ
        }
        DMA1->INTFCR = DMA1_IT_HT5;
    }
    if( DMA1->INTFR & DMA1_IT_TC5)
    {
        CLEAR_BIT(INPUT_DMA_CHANNEL->CFGR,0x1);  //disable DMA1_CH5
        transfercomplete();
        DMA1->INTFCR = DMA1_IT_TC5;
    }
    /* Check whether DMA transfer error caused the DMA interruption */
    if( DMA1->INTFR & DMA1_IT_TE5)
    {
        DMA_ClearFlag(DMA1_IT_TE5);
    }
}


void DMA1_Channel4_IRQHandler(void)
{
    if(DMA_GetITStatus(DMA1_IT_TC4))
    {
        USART_DMACmd(USART1,USART_DMAReq_Tx,DISABLE);
        DMA_Cmd(DMA1_Channel4, DISABLE);
        MODIFY_REG(USART1->CTLR1, 0x3<<2, 0x0<<3);  //¹Ø±Õ·¢ËÍ
        DMA_ClearFlag(DMA1_IT_TC4);
    }
    /* Check whether DMA transfer error caused the DMA interruption */
    if(DMA_GetITStatus(DMA1_IT_TE4))
    {
        USART_DMACmd(USART1,USART_DMAReq_Tx,DISABLE);
        MODIFY_REG(USART1->CTLR1, 0x3<<2, 0x0<<3);  //¹Ø±Õ·¢ËÍ
        DMA_Cmd(DMA1_Channel4, DISABLE);
        DMA_ClearFlag(DMA1_IT_TE4);
    }

}


void SysTick_Handler(void)
{
    SysTick->SR = 0;
    tenKhzRoutine( );
}



void EXTI2_IRQHandler(void)
{
    EXTI->INTFR = EXTI_Line2;
    interruptRoutine( );
}



void TIM3_IRQHandler(void)
{
    if(TIM_GetITStatus(TIM3,TIM_IT_Update))
    {
        PeriodElapsedCallback( );
        TIM_ClearITPendingBit(TIM3, TIM_IT_Update);
    }
}




