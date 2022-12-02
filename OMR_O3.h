/*
 * OMR_O3.h
 *
 *  Created on: 2022/11/27
 *      Author: Owner
 */

#ifndef OMR_O3_H_
#define OMR_O3_H_

//double* Vo[3];
#include "sken_library/include.h"
#include "sken_lib/lib_include.h"


class O3{
	Enc encoder[3];
	Encoder_data Data[3];
	double omuni_vol_01,omuni_vol_02,omuni_vol_03;
    double V[3];
    static
	//void encode_interrupt();
    Pin pin;
public:
	O3();
	void interrupt_prot(Encoder_data omuni_01_data,Encoder_data omuni_02_data,Encoder_data omuni_03_data);
	void vol(Pin Aomuni_a_pin,Pin Aomuni_b_pin,TimerNumber Aomuni_timer,Pin Bomuni_a_pin,Pin Bomuni_b_pin,TimerNumber Bomuni_timer,Pin Comuni_a_pin,Pin Comuni_b_pin,TimerNumber Comuni_timer);
	void init(double bodyR,double wheelR);
	double *read(double V1,double V2,double V3);
};



#endif /* OMR_O3_H_ */
