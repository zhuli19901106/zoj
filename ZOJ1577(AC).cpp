#include <math.h>
#include <stdio.h>

int gcd(int x, int y)
{
	while(1)
	{
		if(x > y)
		{
			if(x % y == 0)
			{
				return y;
			}
			else
			{
				x = x % y;
			}
		}
		else if(x < y)
		{
			if(y % x == 0)
			{
				return x;
			}
			else
			{
				y = y % x;
			}
		}
		else
		{
			return x;
		}
	}
}

int main()
{
	int x;
	int y;
	int i;
	int product;
	double rt;
	int count;

	while(1)
	{
		if(scanf("%d%d", &x, &y) != 2)
		{
			break;
		}
		count = 0;
		product = x * y;
		rt = sqrt(product * 1.0);
		for(i = x; i <= rt; i++)
		{
			if(product % i == 0)
			{
				if(gcd(i, product / i) == x)
				{
					if(i < product / i)
					{
						count = count + 2;
					}
					else if(i == product / i)
					{
						count = count + 1;
					}
				}
			}
		}

		printf("%d\n", count);
	}

	return 0;
}

