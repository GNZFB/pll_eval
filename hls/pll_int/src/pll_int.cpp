#include "pll_int.h"

//#define pi	3.1415926
//#define pi2 3.14159

void pll_int (ap_uint<2> rstIntN, sign_typ input,
		sign_typ Ki, sign_typ Kp,
		sign_typ *w, thet_typ *theta){
	//const data_type Ki = 0.1;
	//const data_type Kp = 0.5;
	const sign_typ pi  = 3.1415926;
	const sign_typ pi2 = 6.2831853;

	sign_typ e, y; // PI error signal, PI output signal
	static sign_typ y_integral;	//accumulators
	static sign_typ w_integral = -pi;
	//Obtain the error value
	e = input;

	//Reset Integral accumulation
	if (rstIntN==0){
		y_integral = 0;
	}
	// PI controller
	y_integral = y_integral + Ki*e;
	y = Kp*e + y_integral;

	// Auto-reseteable integrator
	w_integral = w_integral + y;
	if (w_integral > pi)
		w_integral = w_integral - pi2;

	//Outputs
	*w = y;
	*theta = w_integral;

}
