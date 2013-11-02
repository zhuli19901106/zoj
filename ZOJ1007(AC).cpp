/************************************************************************/
/* ZOJ 1007 Numeric Summation of Series */
/* 2012.2.15, am 7. Lehr-Gebaeude. */
/* Programmiert von Giulio, 3090101804 */
/************************************************************************/
#include <math.h>
#include <stdio.h>

/*#define DEBUG*/

const double lowerbound = 0.000;
const double upperbound = 2.000;
const double inc = 0.001;
const double error = 5e-14;

int main()
{
	int k;
	int stopN;
	double ps;
	double x;

	FILE *fp = fopen("out.txt", "w");
	FILE * fp1 = fopen("stopN.txt", "w");

	for(x = lowerbound; x <= upperbound; x = x + inc)
	{
		/*stopN = (int)ceil(pow((1 - x) * (2 - x) / (error * 3.0), 1.0 / 3.0));*/
		/*stopN = (int)ceil(pow(abs((1 - x) * (2 - x) * (3 - x) / (4 * error)), 1.0 / 4.0));*/
		ps = 0;
		for(k = 1; k <= 6000; k++)
		{
			/*ps = ps + 1.0 / k / (k + 1) / (k + 2) / (k + x);*/
			ps = ps + 1.0 / k / (k + 1) / (k + 2) / (k + 3) / (k + x);
		}
		/* ps = ((2 - x) * ps + 1.0 / 4.0) * (1.0) + 1.0; */
		ps = ((ps * (3 - x) + 1.0 / 18.0) * (2 - x) + 1.0 / 4.0) * (1 - x) + 1.0;
		printf("%5.3f %16.12f\n", x, ps);
#ifdef DEBUG
		fprintf(fp, "%5.3f %16.12f\n", x, ps);
		fprintf(fp1, "%d\n", stopN);
#endif
	}

	return 0;
}

