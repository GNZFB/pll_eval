#ifndef PHASE_GENERATOR_H_
#define PHASE_GENERATOR_H_

#include "ap_fixed.h"
#include <math.h>

// LUT size
#define NLUT 10		// bitwidth for cos lut address, covers one quadrant
#define LUTSIZE 1024   // 2^NLUT
#define PHLUTSIZE 4096   // 2^(NLUT+2)

//Type definitions
typedef ap_uint<NLUT+2> full_adr_t; // covers 4 quadrant
typedef ap_uint<2> 		quad_adr_t; // indicates which quadrant
typedef ap_uint<NLUT>   lut_adr_t;  // covers 1 quadrant

typedef ap_fixed<16,4, AP_RND, AP_SAT> sign_typ;
typedef ap_fixed<16,3, AP_RND, AP_SAT> thet_typ;
//typedef ap_fixed<16,2, AP_RND, AP_SAT> trig_typ;
typedef ap_ufixed<32,32> incr_t, acc_t;

const full_adr_t PHA_OFFSET = 0;
const full_adr_t PHB_OFFSET = 2*4095/3;
const full_adr_t PHC_OFFSET = 4095/3;

void init_cos_lut(sign_typ cos_lut[LUTSIZE]);
void init_phase_lut(thet_typ phase_lut[LUTSIZE]);
sign_typ look_up_sin(sign_typ lut[LUTSIZE], full_adr_t full_adr);
void phase_generator (incr_t incr,
		thet_typ *theta,
		sign_typ *a, sign_typ *b, sign_typ *c );

#endif
