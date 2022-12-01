/*
 * OMR_O3.cpp
 *
 *  Created on: 2022/11/27
 *      Author: Owner
 */
#include "OMR_O3.h"
#include "math.h"
/*Enc encoder[3];
Encoder_data Data[3];*/
#define PI 3.14159265359
	O3::O3(){}

    void O3::encode_interrupt(){
    encoder[0].interrupt(&Data[0]);
    encoder[1].interrupt(&Data[1]);
    encoder[2].interrupt(&Data[2]);
    }

    //encoderの初期設定の為，引数が必要．
void O3::vol(Pin Aomuni_a_pin,Pin Aomuni_b_pin,TimerNumber Aomuni_timer,Pin Bomuni_a_pin,Pin Bomuni_b_pin,TimerNumber Bomuni_timer,Pin Comuni_a_pin,Pin Comuni_b_pin,TimerNumber Comuni_timer){
	sken_system.init();
	encoder[0].init(Aomuni_a_pin,Aomuni_b_pin,Aomuni_timer,50);
	encoder[1].init(Bomuni_a_pin,Bomuni_b_pin,Bomuni_timer,50);
	encoder[2].init(Comuni_a_pin,Comuni_b_pin,Comuni_timer,50);
	sken_system.addTimerInterruptFunc(encode_interrupt,0,1);

	while(true){
		omuni_vol_01 = Data[0].volcity;
		omuni_vol_02 = Data[1].volcity;
		omuni_vol_03 = Data[2].volcity;
	}
}
