#include <stdio.h>

int main()
{
	int count;
	int n;

	while(1)
	{
		scanf("%d", &n);
		if(n == 0)
		{
			break;
		}
		else
		{
			count = 0;
		}

		while(n > 1)
		{
			if(n % 2 == 1)
			{
				n = n / 2 + 1;
			}
			else
			{
				n = n / 2;
			}
			count++;
		}

		printf("%d\n", count);
	}

	return 0;
}

