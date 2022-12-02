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
#include "stm32f4xx_nucleo.h"
#include "math.h"
#include "sken_library/include.h"
#include "sken_lib/lib_include.h"
#include "OMR_O3.h"

	O3 red;
	double a;
	Encoder_data Data_prot[3];
	Enc encoder;


	void encode_interrupt()
	{
	red.interrupt_prot(Data_prot[0],Data_prot[1],Data_prot[2]);
	}

int main(void)
	{
	sken_system.init();
	//encoder.init(B4,B5,TIMER3,50);
	red.vol(B4,B5,TIMER3,A0,A1,TIMER2,A8,A9,TIMER1);//encoder pin timer
	sken_system.addTimerInterruptFunc(encode_interrupt,0,1);
	while(true)
	{
		a = Data_prot[0].deg;
	}

    }


