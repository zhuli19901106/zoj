#include <stdio.h>

int main()
{
	int n;

	while(1)
	{
		if(scanf("%d", &n) != 1)
		{
			break;
		}
		if(n == 0)
		{
			break;
		}

		if(n % 2 == 1)
		{
			printf("%d\n", (n - 1) / 2);
		}
		else
		{
			printf("%d\n", n / 2);
		}
	}

	return 0;
}

