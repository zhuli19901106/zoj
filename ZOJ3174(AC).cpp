#include <math.h>
#include <stdio.h>

int main()
{
	int x;
	int y;
	int year;
	int d2;
	int d3;
	int i;
	int n;
	int count;

	while(1)
	{
		if(scanf("%d", &n) != 1)
		{
			break;
		}

		for(i = 0; i < n; i++)
		{
			scanf("%d%d", &x, &y);
			count = 0;
			for(year = x; year <= y; year++)
			{
				d2 = year % 100;
				d3 = year % 1000;
				if(d3 == d2)
				{
					if(sqrt(1.0 * d2) - (int)sqrt(1.0 * d2) == 0)
					{
						if(sqrt(1.0 * d2) <= 12 && sqrt(1.0 * d2) >= 1)
						{
							count++;
						}
					}
				}
				else
				{
					if(sqrt(1.0 * d2) - (int)sqrt(1.0 * d2) == 0)
					{
						if(sqrt(1.0 * d2) <= 12 && sqrt(1.0 * d2) >= 1)
						{
							count++;
						}
					}

					if(sqrt(1.0 * d3) - (int)sqrt(1.0 * d3) == 0)
					{
						if(sqrt(1.0 * d3) <= 12 && sqrt(1.0 * d3) >= 1)
						{
							count++;
						}
					}
				}
			}

			printf("%d\n", count);
		}
	}

	return 0;
}

