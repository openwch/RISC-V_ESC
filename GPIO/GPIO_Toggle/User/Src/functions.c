/*
 * functions.c
 *
 *  Created on: Sep. 26, 2020
 *      Author: Alka
 */

#include "functions.h"
#include "targets.h"

long map(long x, long in_min, long in_max, long out_min, long out_max)
{
    if (x < in_min){
        x = in_min;
    }
    if (x > in_max){
        x = in_max;
    }
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;

}


int getAbsDif(int number1, int number2){
    int result = number1 - number2;
    if (result < 0) {
        result = -result;
    }
    return result;
}


void delayMicros(uint32_t micros)
{

    uint32_t i;
    i = 24*micros;    //24

    do
    {
        __NOP();
    }while(--i);

#if 0
    UTILITY_TIMER->CNT = 0;
    while (UTILITY_TIMER->CNT < micros*96)
    {

    }
#endif
}

void delayMillis(uint32_t millis)
{
    do
    {
        delayMicros(1000);
    }while( --millis );


#if 0
    UTILITY_TIMER->CNT = 0;
    while (UTILITY_TIMER->CNT < millis*96000)
    {

    }
#endif
}
