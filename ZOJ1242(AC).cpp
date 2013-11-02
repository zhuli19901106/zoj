#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <cstdio>
using namespace std;

int main()
{
	int cc;
	int w;
	int d;
	int year;

	cc = 0;
	while(true)
	{
		scanf("%d%d", &w, &d);
		if(0 == w && 0 == d)
		{
			break;
		}
		else
		{
			cc++;
		}

		year = log(1.0 * d / w / 810.0) / log(0.5) * 5730;

		if(year < 10000)
		{
			year = (year + 50) / 100 * 100;
		}

		if(year >= 10000)
		{
			year = (year + 500) / 1000 * 1000;
		}

		printf("Sample #%d\n", cc);
		printf("The approximate age is %d years.\n", year);
		printf("\n");
	}

	return 0;
}

