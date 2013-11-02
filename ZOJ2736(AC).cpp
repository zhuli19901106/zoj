#include <stdio.h>

int main()
{
	int n;
	int d1;
	int d2;
	int d3;

	while(1)
	{
		if(scanf("%d", &n) == EOF)
		{
			break;
		}
		d1 = n % 10;
		d2 = (n - d1) / 10 % 10;
		d3 = n / 100;

		if(n == d1 * d1 * d1 + d2 * d2 * d2 + d3 * d3 * d3)
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

