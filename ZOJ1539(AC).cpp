#include <stdio.h>

long calc(long n)
{
	if(n < 3)
	{
		return 0;
	}
	else if(n == 3)
	{
		return 1;
	}
	else if(n % 2 == 0)
	{
		return 2 * calc(n / 2);
	}
	else
	{
		return calc((n + 1) / 2) + calc((n - 1) / 2);
	}
}

int main()
{
	long n;

	while(1)
	{
		if(scanf("%ld", &n) != 1)
		{
			break;
		}
		printf("%ld\n", calc(n));
	}

	return 0;
}

