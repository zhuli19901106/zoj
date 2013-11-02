#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
using namespace std;

void swap(double *a, double *b)
{
	double t;

	t = *a;
	*a = *b;
	*b = t;
}

int main()
{
	double x1, x2;
	double y1, y2;
	double r1, r2;
	double d;
	int t;
	int ti;
	double x;
	double y;

	scanf("%d", &t);
	for(ti = 0; ti < t; ti++)
	{
		scanf("%lf%lf%lf", &x1, &y1, &r1);
		scanf("%lf%lf%lf", &x2, &y2, &r2);

		d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
		if(d <= fabs(r2 - r1) || (x1 == x2 && y1 == y2) || (r1 == r2))
		{
			printf("Impossible.\n");
		}
		else
		{
			//(r1 - r2) * p = r1 * p2 - r2 * p1;
			x = (r1 * x2 - r2 * x1) / (r1 - r2);
			y = (r1 * y2 - r2 * y1) / (r1 - r2);

			printf("%0.2f %0.2f\n", x, y);
		}
	}

	return 0;
}

