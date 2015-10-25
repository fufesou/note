/**
 * @file MakeTable.c
 * @brief  
 * @author cxl, <shuanglongchen@yeah.net>
 * @version 0.1
 * @date 2015-10-25
 * @modified  2015-10-26 00:00:59 (+0800)
 */

#include  <stdio.h>
#include  <stdlib.h>
#include  <math.h>
 
int main (int argc, char *argv[])
{
	int i;
	double result;
	FILE *fout;

	// make sure we have enough arguments
	if (argc < 2)
	{
		return 1;
	}

	// open the output file
	fout = fopen(argv[1],"w");
	if (!fout)
	{
		return 1;
	}

	// create a source file with a table of square roots
	fprintf(fout,"double sqrtTable[] = {\n");
	for (i = 0; i < 10; ++i)
	{
		result = sqrt((double)i);
		fprintf(fout,"%g,\n",result);
	}

	// close the table with a zero
	fprintf(fout,"0};\n");
	fclose(fout);
	return 0;
}

