/*
 * OMR_O3.cpp
 *
 *  Created on: 2022/11/27
 *      Author: Owner
 */
#include <OMR_O3.h>
#include "math.h"
#define PI 3.14159265359

float R,L;

void O3_Read::init(double bodyR,double wheelR){
	R = bodyR;
	L = wheelR;
};

double *O3_Read::read(double V1,double V2,double V3){
	V1y = V1-V2;
	V3y = V2-V2;
	V1z = V1-V3;
	V2z = V2-V3;
	V2x = V2-V1;
	V3x = V3-V1;
if(V1==V2 && V1==V3){
	V[2] = V1/R;
	V[0] = 0;
	V[1] = 0;
}else if(V1<=V2 && V1<=V3){
	V[2] = (double)V1;
	V[0] = V2x * sin(a-(1.0/3.0)*PI) + V3x * sin(a+(1.0/3.0)*PI);
	V[1] = V2x * cos(a-(1.0/3.0)*PI) + V3x * cos(a+(1.0/3.0)*PI);
}else if(V2<=V1 && V2<=V3){
	V[2] = (double)V2;
	V[0] = V1y * sin(a+PI) + V3y * sin(a+(1.0/3.0)*PI);
	V[1] = V1y * cos(a+PI) + V3y * cos(a+(1.0/3.0)*PI);
}else if(V3<=V1 && V3<=V2){
	V[2] = (double)V3;
	V[0] = V1z * sin(a+PI) + V2z * sin(a-(1.0/3.0)*PI);
	V[1] = V1z * cos(a+PI) + V2z * cos(a-(1.0/3.0)*PI);
}
	return &V[0];
}


