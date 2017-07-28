#include "abc2alphabeta2dq.h"

//#define alpha_const 0.3333333333 	//1/3
//#define beta_const 0.5773502691 	//sqrt(3)/3

void abc2alphaBeta2dq (sign_typ a, sign_typ b, sign_typ c,
		trig_typ cosTh, trig_typ sinTh,
		sign_typ *alpha, sign_typ *beta,
		sign_typ *d, sign_typ *q){

	const sign_typ alpha_const = 0.3333333333; 	//1/3
	const sign_typ beta_const = 0.5773502691; 	//

	*alpha = (2*a-b-c)*alpha_const;
	*beta = (b-c)*beta_const;

#ifdef DQTRANSF_FLAG_1
	*d = -*alpha*cosTh - *beta*sinTh;
	*q = *beta*cosTh - *alpha*sinTh;
#else
	*d = *alpha*sinTh - *beta*cosTh;
	*q = *alpha*cosTh + *beta*sinTh;
#endif

}
