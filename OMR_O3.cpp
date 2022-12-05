/*
 * OMR_O3.cpp
 *
 *  Created on: 2022/11/27
 *      Author: Owner
 */
#include "OMR_O3.h"
/*Enc encoder[3];
Encoder_data Data[3];*/
#define PI 3.14159265359
	O3::O3(){}

	//encoder0,1,2でオムニ1,2,3.Dataも同じ．

    /*void O3::encode_interrupt(){
    encoder[0].interrupt(&Data[0]);
    encoder[1].interrupt(&Data[1]);
    encoder[2].interrupt(&Data[2]);
    }*/

	/*main関数の割り込みで実体を持たせる関数，構造体Dataはmain関数から触れないため，
	引数にmainで用意した構造体を送り込み，その構造体にDataの中身を代入し値を得るつもり．*/
	 void O3::interrupt_prot(Encoder_data* omuni_01_data,Encoder_data* omuni_02_data,Encoder_data* omuni_03_data)
	 {
	 encoder[0].interrupt(&Data[0]);
	 encoder[1].interrupt(&Data[1]);
	 encoder[2].interrupt(&Data[2]);
	 *omuni_01_data = Data[0];
	 *omuni_02_data = Data[1];
	 *omuni_03_data = Data[2];
	 }



    //encoderの初期設定の為，引数が必要．
void O3::vol(Pin Aomuni_a_pin,Pin Aomuni_b_pin,TimerNumber Aomuni_timer,Pin Bomuni_a_pin,Pin Bomuni_b_pin,TimerNumber Bomuni_timer,Pin Comuni_a_pin,Pin Comuni_b_pin,TimerNumber Comuni_timer){

	encoder[0].init(Aomuni_a_pin,Aomuni_b_pin,Aomuni_timer,50);
	encoder[1].init(Bomuni_a_pin,Bomuni_b_pin,Bomuni_timer,50);
	encoder[2].init(Comuni_a_pin,Comuni_b_pin,Comuni_timer,50);
	//sken_system.addTimerInterruptFunc(encode_interrupt,0,1);


	omuni_vol_01 = Data[0].volcity;
	omuni_vol_02 = Data[1].volcity;
	omuni_vol_03 = Data[2].volcity;

}
