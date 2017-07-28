/*
 * phase_generator.c
 *
 *  Created on: 12/05/2017
 *  Author: GFB
 */
#include "phase_generator.h"

void phase_generator (incr_t incr,
		thet_typ *theta,
		sign_typ *a, sign_typ *b, sign_typ *c ) {

  #pragma HLS pipeline
  //Create LUTs
  sign_typ cos_lut[LUTSIZE];
  thet_typ phase_lut[PHLUTSIZE];
  init_cos_lut(cos_lut);
  init_phase_lut(phase_lut);

  //Phase accumulator
  static acc_t acc = 0; //3<<30;	//32 bit accumulator
  acc += incr;

  //Look up cos/sine table
  full_adr_t full_adr = acc(31,20);		//Cover full quadrant

  *theta = phase_lut[full_adr+PHLUTSIZE/4];
  *a = look_up_sin(cos_lut, full_adr + PHA_OFFSET);
  *b = look_up_sin(cos_lut, full_adr + PHB_OFFSET);
  *c = look_up_sin(cos_lut, full_adr + PHC_OFFSET);
}

void init_cos_lut(sign_typ cos_lut[LUTSIZE]){
  // Store single quadrant
  for (int i=0;i<LUTSIZE;i++) {
	  cos_lut[i] = cos(2*M_PI*(0.0+(float)i)/(4*LUTSIZE));
  }
}

void init_phase_lut(thet_typ phase_lut[PHLUTSIZE]){
  for (int i=0;i<PHLUTSIZE;i++) {
	  phase_lut[i] = -M_PI + 2*M_PI/(PHLUTSIZE)*i;
  }
}

sign_typ look_up_sin(sign_typ lut[LUTSIZE], full_adr_t full_adr){

  quad_adr_t quad = full_adr(11,10);	//Specify which quadrant
  lut_adr_t lut_addr = full_adr(9,0);	//cover 1/4 quadrant
  lut_adr_t	sin_adr;		//cover 1/4 quadrant

  switch (quad){
    case 0:	// 1st Quadrant
      if (lut_addr == 0)
    	return 0;
      else{
        sin_adr = -lut_addr;
        return lut[sin_adr];}
      break;

    case 1:	// 2nd Quadrant
      sin_adr = lut_addr;
      return lut[sin_adr];
      break;

    case 2:	// 3rd Quadrant
      if (lut_addr == 0)
        return 0;
      else {
    	sin_adr = -lut_addr;
        return -lut[sin_adr];}
      break;

    case 3:	// 4th Quadrant
      sin_adr = lut_addr;
      return -lut[sin_adr];
      break;

    default:
      return 0;
      break;
  }
}
