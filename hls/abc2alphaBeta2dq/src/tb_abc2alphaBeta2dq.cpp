#include <stdio.h>
#include "alphabeta2dq.h"
#include "math.h"

int main ()
{
	data_type alfa = 0.1;
	data_type beta = 0.2;
	data_type cosTh = 0.3;
	data_type sinTh = 0.4;
	data_type d;
	data_type q;

	alphabeta2dq (alfa, beta, cosTh, sinTh, &d, &q);
    printf ("Results - d:%f , q:%f", (float)d, (float)q);

    return 0;
}
