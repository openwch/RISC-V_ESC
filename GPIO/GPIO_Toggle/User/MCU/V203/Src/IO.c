/*
 * IO.c
 *
 *  Created on: Sep. 26, 2020
 *      Author: Alka
 */

#include "targets.h"
#include "IO.h"
#include "signal.h"
#include "dshot.h"
#include "serial_telemetry.h"
#include "functions.h"
#include "common.h"



////int max_servo_deviation = 250;
////int servorawinput;
//char ic_timer_prescaler = 1;
//char output_timer_prescaler;
//
////int buffersize = 32;
//
//int buffersize = 2;
//int smallestnumber = 20000;
//uint32_t dma_buffer[64] = {0};
//char out_put = 0;
//char buffer_divider = 44;
//int dshot_runout_timer = 62500;
//uint16_t average_signal_pulse = 0;


volatile char ic_timer_prescaler = 10;
char output_timer_prescaler;

int buffersize = 32;
int smallestnumber = 0;
uint32_t dma_buffer[64] = {0};
char out_put = 0;
char buffer_divider = 44;
uint32_t average_signal_pulse;
uint8_t  buffer_padding = 0;


void changeToInput()
{
//      uint32_t dmacfg;
//
//      dmacfg = INPUT_DMA_CHANNEL->CFGR;  //set to periph --> mem
//      dmacfg &= ~(1<<4);  //clear dirbit
//      INPUT_DMA_CHANNEL->CFGR = dmacfg;


      RCC_APB1PeriphResetCmd(RCC_APB1Periph_TIM2,ENABLE);
      RCC_APB1PeriphResetCmd(RCC_APB1Periph_TIM2,DISABLE);
      IC_TIMER_REGISTER->CCER    =  0;

      if(servoPwm)
      {
          IC_TIMER_REGISTER->CHCTLR1 = 0x1;
      }
      else
      {
          IC_TIMER_REGISTER->CHCTLR1 = 0x3;
          IC_TIMER_REGISTER->SMCFGR  = (0x1<<6);  //启用边沿检测器
      }

      IC_TIMER_REGISTER->PSC = ic_timer_prescaler;
      IC_TIMER_REGISTER->ATRLR = 0xffff;
      IC_TIMER_REGISTER->INTFR = 0;
      TIM_GenerateEvent(IC_TIMER_REGISTER,TIM_EventSource_Update);
      out_put = 0;
}



void receiveDshotDma()
{
    changeToInput();

    INPUT_DMA_CHANNEL->MADDR = (uint32_t)&dma_buffer[0];
    INPUT_DMA_CHANNEL->PADDR = (uint32_t)&IC_TIMER_REGISTER->CH1CVR,
    INPUT_DMA_CHANNEL->CNTR  = buffersize;

    INPUT_DMA_CHANNEL->CFGR  = 0x98b;
//    INPUT_DMA_CHANNEL->CFGR  = 0x98f;     //使能传输错误中断，传输完成中断，传输过半中断，方向到mem 使能

    IC_TIMER_REGISTER->CNT = 0;
    IC_TIMER_REGISTER->DMAINTENR |= TIM_DMA_CC1;
    IC_TIMER_REGISTER->CCER |= (1<<0);           //CC3E
    IC_TIMER_REGISTER->CTLR1  |= (1<<0);         //TIM EN
}


void changeToOutput()
{

#ifdef USE_TIMER_2_CHANNEL_1
      RCC_APB1PeriphResetCmd(RCC_APB1Periph_TIM2,ENABLE);
      RCC_APB1PeriphResetCmd(RCC_APB1Periph_TIM2,DISABLE);
      IC_TIMER_REGISTER->CHCTLR1 = 0x60;       //PWM1模式
      IC_TIMER_REGISTER->CCER    = (0x3<<0);   //输出
#endif

      IC_TIMER_REGISTER->PSC = output_timer_prescaler;
      IC_TIMER_REGISTER->ATRLR = 61;
      out_put = 1;
      TIM_GenerateEvent(IC_TIMER_REGISTER,TIM_EventSource_Update);
}




void sendDshotDma(){

    changeToOutput();

           INPUT_DMA_CHANNEL->MADDR = (uint32_t)&gcr;
           INPUT_DMA_CHANNEL->PADDR = (uint32_t)&IC_TIMER_REGISTER->CH3CVR,
           INPUT_DMA_CHANNEL->CNTR  = 23 + buffer_padding ;
           INPUT_DMA_CHANNEL->CFGR  = 0x99b;

           IC_TIMER_REGISTER->DMAINTENR |= TIM_DMA_CC1;
           IC_TIMER_REGISTER->CCER |= (1<<0);           //CC1E
           IC_TIMER_REGISTER->CTLR1  |= (1<<0);         //TIM EN


//              IC_TIMER_REGISTER->DIER |= TIM_DIER_CC1DE;
//              IC_TIMER_REGISTER->CCER |= IC_TIMER_CHANNEL;
//              IC_TIMER_REGISTER->BDTR |= TIM_BDTR_MOE;
//              IC_TIMER_REGISTER->CR1  |= TIM_CR1_CEN;

}




void checkDshot(){
    if ((smallestnumber >= 1)&&(smallestnumber < 3)&& (average_signal_pulse < 50)) {       //600   1.4.50
        PRINT("dshort input1\r\n");
        ic_timer_prescaler= 0;
        output_timer_prescaler=0;
        dshot = 1;
        buffer_divider = 44;
        buffer_padding = 9;

        buffersize = 32;
        inputSet = 1;
    }
    if ((smallestnumber >= 3 )&&(smallestnumber < 8)&& (average_signal_pulse < 50)){      //300  4.8.50
        PRINT("dshort input2\r\n");
        dshot = 1;
        ic_timer_prescaler=1;
        output_timer_prescaler=1;
        IC_TIMER_REGISTER->CNT = 0xffff;
        buffer_divider = 44;
        buffer_padding = 7;

        buffersize = 32;
        inputSet = 1;
    }
}

void checkServo(){
    if (smallestnumber > 300 && smallestnumber < 20000){  //300.20000
        PRINT("servo input\r\n");
        servoPwm = 1;
        ic_timer_prescaler=47;           //47
        armed_count_threshold = 35;
        buffersize = 2;
        inputSet = 1;
    }
}


void detectInput( )
{
    smallestnumber = 20000;            //20000
    average_signal_pulse = 0;
    int lastnumber = dma_buffer[0];

    for(uint8_t i=0;i<32;i++)
    {
        PRINT("%d  ",dma_buffer[i]);
    }
    PRINT("\r\n");

    for ( int j = 1 ; j < 31; j++)
    {
        if(dma_buffer[j] - lastnumber > 0 )
        {
            if((dma_buffer[j] - lastnumber) < smallestnumber)
            {
                smallestnumber = dma_buffer[j] - lastnumber;
            }
            average_signal_pulse += (dma_buffer[j] - lastnumber);
        }
        lastnumber = dma_buffer[j];
    }
    average_signal_pulse = average_signal_pulse/32 ;

    PRINT("smallestnumber:%d  average:%d  %x\r\n",smallestnumber,average_signal_pulse,INPUT_DMA_CHANNEL->MADDR );
    if(dshot == 1)
    {
        checkDshot();
    }
    if(servoPwm == 1)
    {
        checkServo();
    }

    if(!dshot && !servoPwm)
    {
        PRINT("===================================\r\n");
        checkDshot();
        checkServo();
    }

}

