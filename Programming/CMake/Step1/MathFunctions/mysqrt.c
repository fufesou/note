/**
 * @file MathFunctions.c
 * @brief  
 * @author cxl, <shuanglongchen@yeah.net>
 * @version 0.1
 * @date 2015-10-25
 * @modified  2015-10-26 00:22:17 (+0800)
 */

#include  <stdio.h>
#include    "MathFunctions.h"
#include    "TutorialConfig.h"

// include the generated table
#include    "Table.h"

#include  <math.h>

double mysqrt(double x)
{
	int i;
	double result;
	double delta;  

	if (x <= 0)
	{
		return 0;
	}

	// if we have both log and exp then use them
#if defined(HAVE_LOG) && define (HAVE_EXP)
	result = exp(log(x)*0.5);
	fprintf(stdout, "computing sqrt of %g to be %g using log\n", x, result);
#else
	result = x;

	if (x >= 1 && x < 10)
	{
		result = sqrtTable[(int)x];
	}

	for (i = 0; i < 10; ++i)
	{
		if (result <= 0)
		{
			result = 0.1;
		}
		delta = x - (result*result);
		result = result + 0.5*delta/result;
		fprintf(stdout,"Computing sqrt of %g to be %g\n",x,result);
	}
#endif
	return result;
}
