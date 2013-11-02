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
		else if(n == 0)
		{
			break;
		}
		else
		{
			printf("%d\n", n / 2);
		}
	}

	return 0;
}

