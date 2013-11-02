#include <stdio.h>

int main()
{
	long long int n;
	long long int n0;
	long long int i;
	int casecounter;
	FILE *fp;

	casecounter = 0;
	while(1)
	{
		if(scanf("%lld", &n) != 1)
		{
			break;
		}
		else
		{
			if(n < 0)
			{
				break;
			}
			else
			{
				casecounter++;
			}
		}

		if(n == 1)
		{
			printf("%lld\n", n);
			continue;
		}

		n0 = n;
		for(i = 2; i * i <= n; i++)
		{
			if(n % i == 0)
			{
				while(n % i == 0)
				{
					printf("%lld\n", i);
					n = n / i;
				}
			}
		}

		if(n > 1)
		{
			printf("%lld\n", n);
		}
		printf("\n");
	}

	return 0;
}

