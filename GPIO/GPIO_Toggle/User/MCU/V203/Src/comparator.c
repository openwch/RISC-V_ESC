/*
 * comparator.c
 *
 *  Created on: Sep. 26, 2020
 *      Author: Alka
 */

#include "comparator.h"
#include "targets.h"

//PA2 is entry of all compare interrupts
void maskPhaseInterrupts()
{
    EXTI->INTENR &= ~(1 << 2);  //mask
    EXTI->INTFR  = (1<<2);      //clear_flag
}

void enableCompInterrupts()      //enable
{
    EXTI->INTENR |= (1 << 2);
}
void changeCompInput()
{
    //  TIM3->CNT = 0;
    if (step == 1 || step == 4)
    {   // c floating
        OPA->CR = 0x01;
    }
    if (step == 2 || step == 5)
    {   // a floating
        OPA->CR = 0x70;
    }
    if (step == 3 || step == 6)
    {   // b floating
        OPA->CR = 0x30;
    }

    if (rising)
    {
        EXTI->RTENR = 0;
        EXTI->FTENR = (1<<2);  //反向
    }
    else
    {
        EXTI->FTENR = 0;
        EXTI->RTENR = (1<<2);  //反向
    }


}




