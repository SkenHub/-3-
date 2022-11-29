/*
 * OMR_O3.h
 *
 *  Created on: 2022/11/27
 *      Author: Owner
 */

#ifndef OMR_O3_H_
#define OMR_O3_H_

double* Vo[3];



class O3_Read{
	double a,V1y,V2x,V3y,V3x,V1z,V2z;
    double V[3];
public:
	O3_Read(void);
	void init(double bodyR,double wheelR);
	double *read(double V1,double V2,double V3);
};



#endif /* OMR_O3_H_ */
