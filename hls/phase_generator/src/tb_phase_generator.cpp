#include "phase_generator.h"

int main(){

//ofstream fp_dout ("ddsout.txt");
//ofstream fp_fine ("ddsfine.txt");

incr_t  incr;
thet_typ   th;
sign_typ a, b, c;

incr = 1.0*pow(2,-14);;//303.33333*pow(2,-11);

for (int k=0;k<16*4096;k++) {
	phase_generator (incr, &th, &a, &b, &c );

    //fp_fine << setw(10) << k;
    //cout << ", " << scientific << a;
    cout << scientific << a << ", " << scientific << b << ", " << scientific << c << endl;

}


//fp_dout.close();
//fp_fine.close();


return 0;

}
