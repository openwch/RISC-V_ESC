/*
 * phaseouts.c
 *
 *  Created on: Apr 22, 2020
 *      Author: Alka
 */
#include "phaseouts.h"
#include "targets.h"

extern char comp_pwm;
extern char prop_brake_active;

#ifndef PWM_ENABLE_BRIDGE

#ifdef USE_INVERTED_LOW
	#pragma message ("using inverted low side output")
	#define LOW_BITREG_ON  BCR
	#define LOW_BITREG_OFF BSHR
#else
	#define LOW_BITREG_ON  BSHR
	#define LOW_BITREG_OFF BCR
#endif

#ifdef USE_INVERTED_HIGH
	#pragma message ("using inverted high side output")
	//#define HIGH_BITREG_ON  BCR
	#define HIGH_BITREG_OFF BSHR
#else
	//#define HIGH_BITREG_ON  BSHR
	#define HIGH_BITREG_OFF BCR
#endif



/*
 * T1CH1---PA8       CH
 * T1CH2---PA9       BH
 * T1CH3---PA10      AH
 * T1CH1N--PA7       CL
 * T1CH2N--PB0       BL
 * T1CH3N--PB1       AL
 * */



void proportionalBrake(){  // alternate all channels between braking (ABC LOW) and coasting (ABC float)
	                        // put lower channel into alternate mode and turn upper OFF for each channel
	// turn all HIGH channels off for ABC
	PHASE_A_GPIO_PORT_HIGH->CFGHR &= ~(0xf<<8); PHASE_A_GPIO_PORT_HIGH->CFGHR |= (0x3<<8);
	PHASE_A_GPIO_PORT_HIGH->HIGH_BITREG_OFF = PHASE_A_GPIO_HIGH;

	PHASE_B_GPIO_PORT_HIGH->CFGHR &= ~(0xf<<4); PHASE_B_GPIO_PORT_HIGH->CFGHR |= (0x3<<4);
	PHASE_B_GPIO_PORT_HIGH->HIGH_BITREG_OFF = PHASE_B_GPIO_HIGH;

    PHASE_C_GPIO_PORT_HIGH->CFGHR &= ~(0xf<<0); PHASE_C_GPIO_PORT_HIGH->CFGHR |= (0x3<<0);
	PHASE_C_GPIO_PORT_HIGH->HIGH_BITREG_OFF = PHASE_C_GPIO_HIGH;


	// set low channel to PWM, duty cycle will now control braking
    PHASE_A_GPIO_PORT_LOW->CFGLR  &= ~(0xf<<4); PHASE_A_GPIO_PORT_LOW->CFGLR|= (0xb<<4);
    PHASE_B_GPIO_PORT_LOW->CFGLR  &= ~(0xf<<0); PHASE_B_GPIO_PORT_LOW->CFGLR|= (0xb<<0);
    PHASE_C_GPIO_PORT_LOW->CFGLR  &= ~(0xf<<28); PHASE_C_GPIO_PORT_LOW->CFGLR|= (0xb<<28);
}


void phaseBPWM() {
		if(!comp_pwm){  // for future
		    PHASE_B_GPIO_PORT_LOW->CFGLR  &= ~(0xf<<0); PHASE_B_GPIO_PORT_LOW->CFGLR|= (0x3<<0);
		    PHASE_B_GPIO_PORT_LOW->LOW_BITREG_OFF = PHASE_B_GPIO_LOW; //low close
		}else{
		    PHASE_B_GPIO_PORT_LOW->CFGLR  &= ~(0xf<<0); PHASE_B_GPIO_PORT_LOW->CFGLR|= (0xb<<0); //low pwm
		}
		PHASE_B_GPIO_PORT_HIGH->CFGHR &= ~(0xf<<4); PHASE_B_GPIO_PORT_HIGH->CFGHR |= (0xb<<4);   //high pwm
}


void phaseBFLOAT()
{
    PHASE_B_GPIO_PORT_LOW->CFGLR  &= ~(0xf<<0); PHASE_B_GPIO_PORT_LOW->CFGLR|= (0x3<<0);
    PHASE_B_GPIO_PORT_LOW->LOW_BITREG_OFF = PHASE_B_GPIO_LOW;  //low close

    PHASE_B_GPIO_PORT_HIGH->CFGHR &= ~(0xf<<4); PHASE_B_GPIO_PORT_HIGH->CFGHR |= (0x3<<4);
    PHASE_B_GPIO_PORT_HIGH->HIGH_BITREG_OFF = PHASE_B_GPIO_HIGH; //high close
}


void phaseBLOW()
{
	// low mosfet on
    PHASE_B_GPIO_PORT_LOW->CFGLR  &= ~(0xf<<0); PHASE_B_GPIO_PORT_LOW->CFGLR|= (0x3<<0);
    PHASE_B_GPIO_PORT_LOW->LOW_BITREG_ON = PHASE_B_GPIO_LOW;

    // high close
    PHASE_B_GPIO_PORT_HIGH->CFGHR &= ~(0xf<<4); PHASE_B_GPIO_PORT_HIGH->CFGHR |= (0x3<<4);
    PHASE_B_GPIO_PORT_HIGH->HIGH_BITREG_OFF = PHASE_B_GPIO_HIGH;
}



//////////////////////////////PHASE 2//////////////////////////////////////////////////
void phaseCPWM()
{
	if (!comp_pwm)
	{
	    PHASE_C_GPIO_PORT_LOW->CFGLR  &= ~(0xf<<28); PHASE_C_GPIO_PORT_LOW->CFGLR |= (0x3<<28);
		PHASE_C_GPIO_PORT_LOW->LOW_BITREG_OFF = PHASE_C_GPIO_LOW;
	}
	else
	{
	    PHASE_C_GPIO_PORT_LOW->CFGLR  &= ~(0xf<<28); PHASE_C_GPIO_PORT_LOW->CFGLR |= (0xb<<28);
	}
	    PHASE_C_GPIO_PORT_HIGH->CFGHR &= ~(0xf<<0); PHASE_C_GPIO_PORT_HIGH->CFGHR |= (0xb<<0);
}


void phaseCFLOAT()
{
	// floating
    PHASE_C_GPIO_PORT_LOW->CFGLR  &= ~(0xf<<28); PHASE_C_GPIO_PORT_LOW->CFGLR |= (0x3<<28);
	PHASE_C_GPIO_PORT_LOW->LOW_BITREG_OFF = PHASE_C_GPIO_LOW;  //low close

	PHASE_C_GPIO_PORT_HIGH->CFGHR &= ~(0xf<<0); PHASE_C_GPIO_PORT_HIGH->CFGHR |= (0x3<<0);
	PHASE_C_GPIO_PORT_HIGH->HIGH_BITREG_OFF = PHASE_C_GPIO_HIGH;//high close
}



void phaseCLOW() {
        PHASE_C_GPIO_PORT_LOW->CFGLR  &= ~(0xf<<28); PHASE_C_GPIO_PORT_LOW->CFGLR |= (0x3<<28);
		PHASE_C_GPIO_PORT_LOW->LOW_BITREG_ON = PHASE_C_GPIO_LOW; //low on

		PHASE_C_GPIO_PORT_HIGH->CFGHR &= ~(0xf<<0); PHASE_C_GPIO_PORT_HIGH->CFGHR |= (0x3<<0);
		PHASE_C_GPIO_PORT_HIGH->HIGH_BITREG_OFF = PHASE_C_GPIO_HIGH; //high close
}



///////////////////////////////////////////////PHASE 3 /////////////////////////////////////////////////

void phaseAPWM(){
		if (!comp_pwm){
		        PHASE_A_GPIO_PORT_LOW->CFGLR  &= ~(0xf<<4); PHASE_A_GPIO_PORT_LOW->CFGLR|= (0x3<<4);
		        PHASE_A_GPIO_PORT_LOW->LOW_BITREG_OFF = PHASE_A_GPIO_LOW; //low close
			}else{
			    PHASE_A_GPIO_PORT_LOW->CFGLR  &= ~(0xf<<4); PHASE_A_GPIO_PORT_LOW->CFGLR|= (0xb<<4);//low pwm
			}
		PHASE_A_GPIO_PORT_HIGH->CFGHR &= ~(0xf<<8); PHASE_A_GPIO_PORT_HIGH->CFGHR |= (0xb<<8); //high pwm
	}

void phaseAFLOAT() {
        PHASE_A_GPIO_PORT_LOW->CFGLR  &= ~(0xf<<4); PHASE_A_GPIO_PORT_LOW->CFGLR|= (0x3<<4);
		PHASE_A_GPIO_PORT_LOW->LOW_BITREG_OFF = PHASE_A_GPIO_LOW;  //low close

		PHASE_A_GPIO_PORT_HIGH->CFGHR &= ~(0xf<<8); PHASE_A_GPIO_PORT_HIGH->CFGHR |= (0x3<<8);
		PHASE_A_GPIO_PORT_HIGH->HIGH_BITREG_OFF = PHASE_A_GPIO_HIGH; //high close
	}

void phaseALOW() {
        PHASE_A_GPIO_PORT_LOW->CFGLR  &= ~(0xf<<4); PHASE_A_GPIO_PORT_LOW->CFGLR|= (0x3<<4);
		PHASE_A_GPIO_PORT_LOW->LOW_BITREG_ON = PHASE_A_GPIO_LOW;   // low on

		PHASE_A_GPIO_PORT_HIGH->CFGHR &= ~(0xf<<8); PHASE_A_GPIO_PORT_HIGH->CFGHR |= (0x3<<8);
		PHASE_A_GPIO_PORT_HIGH->HIGH_BITREG_OFF = PHASE_A_GPIO_HIGH; //high close
	}

#else

//////////////////////////////////PHASE 1//////////////////////
void phaseBPWM() {
		if(!comp_pwm){            // for future
		//LL_GPIO_SetPinMode(PHASE_B_GPIO_PORT_LOW, PHASE_B_GPIO_LOW, LL_GPIO_MODE_OUTPUT);
		//PHASE_B_GPIO_PORT_LOW->LOW_BITREG_OFF = PHASE_B_GPIO_LOW;
		}else{
		LL_GPIO_SetPinMode(PHASE_B_GPIO_PORT_ENABLE, PHASE_B_GPIO_ENABLE, LL_GPIO_MODE_OUTPUT); // enable on
		PHASE_B_GPIO_PORT_ENABLE->BSRR = PHASE_B_GPIO_ENABLE;
		}
		LL_GPIO_SetPinMode(PHASE_B_GPIO_PORT_PWM, PHASE_B_GPIO_PWM, LL_GPIO_MODE_ALTERNATE);  // high pwm
	}


void phaseBFLOAT() {
	LL_GPIO_SetPinMode(PHASE_B_GPIO_PORT_ENABLE, PHASE_B_GPIO_ENABLE, LL_GPIO_MODE_OUTPUT); // enable off
	PHASE_B_GPIO_PORT_ENABLE->BRR = PHASE_B_GPIO_ENABLE;
		LL_GPIO_SetPinMode(PHASE_B_GPIO_PORT_PWM, PHASE_B_GPIO_PWM, LL_GPIO_MODE_OUTPUT);  // pwm off
		PHASE_B_GPIO_PORT_PWM->BRR = PHASE_B_GPIO_PWM;
	}


void phaseBLOW() {
	        // low mosfet on
	LL_GPIO_SetPinMode(PHASE_B_GPIO_PORT_ENABLE, PHASE_B_GPIO_ENABLE, LL_GPIO_MODE_OUTPUT);  // enable on
	PHASE_B_GPIO_PORT_ENABLE->BSRR = PHASE_B_GPIO_ENABLE;
		LL_GPIO_SetPinMode(PHASE_B_GPIO_PORT_PWM, PHASE_B_GPIO_PWM, LL_GPIO_MODE_OUTPUT);  // pwm off
		PHASE_B_GPIO_PORT_PWM->BRR = PHASE_B_GPIO_PWM;
}



//////////////////////////////PHASE 2//////////////////////////////////////////////////


void phaseCPWM() {
	if (!comp_pwm){
		//	LL_GPIO_SetPinMode(PHASE_C_GPIO_PORT_LOW, PHASE_C_GPIO_LOW, LL_GPIO_MODE_OUTPUT);
			//PHASE_C_GPIO_PORT_LOW->LOW_BITREG_OFF = PHASE_C_GPIO_LOW;
		}else{
			LL_GPIO_SetPinMode(PHASE_C_GPIO_PORT_ENABLE, PHASE_C_GPIO_ENABLE, LL_GPIO_MODE_OUTPUT);  // enable on
			PHASE_C_GPIO_PORT_ENABLE->BSRR = PHASE_C_GPIO_ENABLE;
		}
		LL_GPIO_SetPinMode(PHASE_C_GPIO_PORT_PWM, PHASE_C_GPIO_PWM, LL_GPIO_MODE_ALTERNATE);

	}


void phaseCFLOAT() {
	         // floating
	LL_GPIO_SetPinMode(PHASE_C_GPIO_PORT_ENABLE, PHASE_C_GPIO_ENABLE, LL_GPIO_MODE_OUTPUT);  // enable off
				PHASE_C_GPIO_PORT_ENABLE->BRR = PHASE_C_GPIO_ENABLE;
		LL_GPIO_SetPinMode(PHASE_C_GPIO_PORT_PWM, PHASE_C_GPIO_PWM, LL_GPIO_MODE_OUTPUT);
		PHASE_C_GPIO_PORT_PWM->BRR = PHASE_C_GPIO_PWM;
	}



void phaseCLOW() {
	LL_GPIO_SetPinMode(PHASE_C_GPIO_PORT_ENABLE, PHASE_C_GPIO_ENABLE, LL_GPIO_MODE_OUTPUT);  // enable on
		PHASE_C_GPIO_PORT_ENABLE->BSRR = PHASE_C_GPIO_ENABLE;
		LL_GPIO_SetPinMode(PHASE_C_GPIO_PORT_PWM, PHASE_C_GPIO_PWM, LL_GPIO_MODE_OUTPUT);
		PHASE_C_GPIO_PORT_PWM->BRR = PHASE_C_GPIO_PWM;
	}



///////////////////////////////////////////////PHASE 3 /////////////////////////////////////////////////

void phaseAPWM() {
		if (!comp_pwm){
		//	LL_GPIO_SetPinMode(PHASE_A_GPIO_PORT_LOW, PHASE_A_GPIO_LOW, LL_GPIO_MODE_OUTPUT);
			//PHASE_A_GPIO_PORT_LOW->LOW_BITREG_OFF = PHASE_A_GPIO_LOW;
			}else{
				LL_GPIO_SetPinMode(PHASE_A_GPIO_PORT_ENABLE, PHASE_A_GPIO_ENABLE, LL_GPIO_MODE_OUTPUT);  // enable on
				PHASE_A_GPIO_PORT_ENABLE->BSRR = PHASE_A_GPIO_ENABLE;
			}
		LL_GPIO_SetPinMode(PHASE_A_GPIO_PORT_PWM, PHASE_A_GPIO_PWM, LL_GPIO_MODE_ALTERNATE);
	}

void phaseAFLOAT() {
		LL_GPIO_SetPinMode(PHASE_A_GPIO_PORT_ENABLE, PHASE_A_GPIO_ENABLE, LL_GPIO_MODE_OUTPUT);  // enable on
		PHASE_A_GPIO_PORT_ENABLE->BRR = PHASE_A_GPIO_ENABLE;
		LL_GPIO_SetPinMode(PHASE_A_GPIO_PORT_PWM, PHASE_A_GPIO_PWM, LL_GPIO_MODE_OUTPUT);
		PHASE_A_GPIO_PORT_PWM->BRR = PHASE_A_GPIO_PWM;
	}

void phaseALOW() {
		LL_GPIO_SetPinMode(PHASE_A_GPIO_PORT_ENABLE, PHASE_A_GPIO_ENABLE, LL_GPIO_MODE_OUTPUT);  // enable on
		PHASE_A_GPIO_PORT_ENABLE->BSRR = PHASE_A_GPIO_ENABLE;
		LL_GPIO_SetPinMode(PHASE_A_GPIO_PORT_PWM, PHASE_A_GPIO_PWM, LL_GPIO_MODE_OUTPUT);
		PHASE_A_GPIO_PORT_PWM->BRR = PHASE_A_GPIO_PWM;
	}



#endif

void allOff(){
	phaseAFLOAT();
	phaseBFLOAT();
	phaseCFLOAT();
}


void  comStep (int newStep){
//TIM14->CNT = 0;
switch(newStep)
{

        case 1:			//A-B
        	phaseAPWM();
        	phaseBLOW();
        	phaseCFLOAT();
        	break;


        case 2:		// C-B
        	phaseAFLOAT();
        	phaseBLOW();
        	phaseCPWM();
        	break;



        case 3:	// C-A
        	phaseALOW();
        	phaseBFLOAT();
        	phaseCPWM();
        	break;


        case 4:// B-A
        	phaseALOW();
        	phaseBPWM();
        	phaseCFLOAT();
        	break;


        case 5:    // B-C
        	phaseAFLOAT();
        	phaseBPWM();
        	phaseCLOW();
        	break;


        case 6:      // A-C
        	phaseAPWM();
        	phaseBFLOAT();
        	phaseCLOW();
        	break;
	}

//stop_time = TIM14->CNT;

}

void fullBrake(){                     // full braking shorting all low sides
	phaseALOW();
	phaseBLOW();
	phaseCLOW();
}


void allpwm(){                        // for stepper_sine
	phaseAPWM();
	phaseBPWM();
	phaseCPWM();
}


void twoChannelForward(){
phaseAPWM();
phaseBLOW();
phaseCPWM();
}

void twoChannelReverse(){
phaseALOW();
phaseBPWM();
phaseCLOW();
}

