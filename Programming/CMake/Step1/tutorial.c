/**
 * @file tutorial.c
 * @brief  
 * @author cxl, <shuanglongchen@yeah.net>
 * @version 0.1
 * @date 2015-10-25
 * @modified  2015-10-26 00:08:11 (+0800)
 */

#include  <stdio.h>
#include  <stdlib.h>
#include  <math.h>
#include    "TutorialConfig.h"
#ifdef USE_MYMATH
#include    "MathFunctions.h"
#endif

int main(int argc, char *argv[])
{
	double inputValue;
	double outputValue;

	if (argc < 2)
	{
		fprintf(stdout, "%s Version: %d.%d\n",
					argv[0],
					Tutorial_VERSION_MAJOR,
					Tutorial_VERSION_MINOR);
		fprintf(stdout, "Usage: %s number\n", argv[0]);
		return 1;
	}

	inputValue = atof(argv[1]);

#ifdef USE_MYMATH
	outputValue = mysqrt(inputValue);
#else
	outputValue = sqrt(inputValue);
#endif

	fprintf(stdout, "The square root of %g is %g\n", inputValue, outputValue);

	return 0;
}
