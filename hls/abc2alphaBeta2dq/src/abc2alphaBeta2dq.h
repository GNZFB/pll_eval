#ifndef H_ABC2ALPHABETA2DQ_H
#define H_ABC2ALPHABETA2DQ_H

#include <ap_fixed.h>

typedef ap_fixed<16,4, AP_RND, AP_SAT> sign_typ;
//typedef ap_fixed<16,3, AP_RND, AP_SAT> thet_typ;
typedef ap_fixed<16,2, AP_RND, AP_SAT> trig_typ;

void abc2alphaBeta2dq (sign_typ a, sign_typ b, sign_typ c,
		trig_typ cosTh, trig_typ sinTh,
		sign_typ *alpha, sign_typ *beta,
		sign_typ *d, sign_typ *q);

#endif //#ifndef H_ABC2ALPHABETA2DQ_H
