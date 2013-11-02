#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

typedef struct stime{
	int hour;
	int minute;
	double hangle;
	double mangle;
	double angle;
}stime;

int comparator(const void *a, const void *b)
{
	return ((stime *)a)->angle >  ((stime *)b)->angle;
}

int main()
{
	int i;
	int j;
	int n;
	stime a[5];

	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < 5; j++)
		{
			scanf("%02d:%02d", &a[j].hour, &a[j].minute);
			a[j].mangle = 6 * a[j].minute;
			a[j].hangle = 30 * (a[j].hour % 12) + 30 * a[j].minute / 60.0;
			a[j].angle = a[j].hangle - a[j].mangle;
			if(a[j].angle > -360 && a[j].angle <= -180)
			{
				a[j].angle = a[j].angle + 360;
			}
			else if(a[j].angle > -180 && a[j].angle <= 0)
			{
				a[j].angle = -a[j].angle;
			}
			else if(a[j].angle > 0 && a[j].angle <= 180)
			{
				a[j].angle = a[j].angle;
			}
			else if(a[j].angle > 180 && a[j].angle <= 360)
			{
				a[j].angle = 360 - a[j].angle;
			}
		}

		qsort(a, 5, sizeof(stime), comparator);
		printf("%02d:%02d\n", a[2].hour, a[2].minute);
	}

	return 0;
}

