#include <math.h>
#include <stdio.h>

int main()
{
	double a;
	double b;
	double tmp;
	double r1;
	double r2;
	int yes;

	while(1)
	{
		if(scanf("%lf%lf%lf%lf", &a, &b, &r1, &r2) != 4)
		{
			break;
		}

		if(a > b)
		{
			tmp = a;
			a = b;
			b = tmp;
		}

		if(r1 > r2)
		{
			tmp = r1;
			r1 = r2;
			r2 = tmp;
		}

		yes = 1;
		if(2 * r2 > a)
		{
			yes = 0;
		}

		if(yes == 1 && sqrt((r1 + r2) * (r1 + r2) - (a - r1 - r2) * (a - r1 - r2)) + r1 + r2 > b)
		{
			yes = 0;
		}

		if(yes == 1)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}

	return 0;
}

