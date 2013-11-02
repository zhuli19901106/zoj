#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	double a;
	double l;
	double r;
	double mid;
	double fl;
	double fr;
	double fa;
	double fmid;
	const double e = 2.71828;
	const double error = 1e-6;

	while(1)
	{
		if(scanf("%lf", &a) != 1)
		{
			break;
		}
		else if(a <= 1 || a > e)
		{
			printf("-1\n");
			continue;
		}
		else
		{
			fa = log(a) / a;
			if(a < e)
			{
				l = e;
				r = 1e307;
			}
			else
			{
				printf("-1\n");
				continue;
			}

			while(fabs(l - r) >= error || fabs(fl - fr) >= error)
			{
				mid = l + (r - l) / 2.0;
				fl = log(l) / l;
				fr = log(r) / r;
				fmid = log(mid) / mid;
				if(fa > fmid)
				{
					r = mid;
					fr = fmid;
				}
				else if(fa < fmid)
				{
					l = mid;
					fl = fmid;
				}
			}

			if(mid >= a)
			{
				printf("%0.5f\n", mid);
			}
			else
			{
				printf("-1\n");
			}
		}
	}

	return 0;
}

