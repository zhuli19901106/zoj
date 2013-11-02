#include <stdio.h>

int main()
{
	int t;
	int i;
	int n;

	while(1)
	{
		if(scanf("%d", &t) != 1)
		{
			break;
		}

		for(i = 0; i < t; i++)
		{
			scanf("%d", &n);
			printf("%d", n);
			if(n % 100 - n % 10 == 10)
			{
				printf("th\n");
			}
			else if(n % 10 == 1)
			{
				printf("st\n");
			}
			else if(n % 10 == 2)
			{
				printf("nd\n");
			}
			else if(n % 10 == 3)
			{
				printf("rd\n");
			}
			else
			{
				printf("th\n");
			}
		}
	}

	return 0;
}

