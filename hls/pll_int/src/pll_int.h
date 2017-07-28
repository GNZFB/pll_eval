#ifndef H_PLL_INT_H
#define H_PLL_INT_H

#include <ap_fixed.h>

typedef ap_fixed<16,4, AP_RND, AP_SAT> sign_typ;
typedef ap_fixed<16,3, AP_RND, AP_SAT> thet_typ;
//typedef ap_fixed<16,2, AP_RND_CONV, AP_SAT_SYM> trig_typ;

void pll_int (bool rstIntN, sign_typ input,
		sign_typ Ki, sign_typ Kp,
		sign_typ *w, thet_typ *theta);

#endif //#ifndef H_PLL_INT_H
