#include <stdio.h>
#define MAXLEN 161

int main()
{
	char buffer[1000];
	int n;
	int i;
	int a[MAXLEN];
	int sum[MAXLEN];
	int result;
	int t;
	int j;

	for(i = 0; i < MAXLEN; i++)
	{
		a[i] = i * (i + 1) / 2;
	}

	sum[0] = 0;
	for(i = 1; i < MAXLEN; i++)
	{
		sum[i] = sum[i - 1] + i * i;
	}

	gets(buffer);
	sscanf(buffer, "%d", &t);

	for(j = 0; j < t; j++)
	{
		if(j >  0)
		{
			printf("\n");
		}
		gets(buffer);
		while(1)
		{
			gets(buffer);
			sscanf(buffer, "%d", &n);
			if(n == 0)
			{
				break;
			}

			for(i = 0; i < MAXLEN; i++)
			{
				if(a[i] > n)
				{
					break;
				}
			}

			result = sum[i - 1] + (n - a[i - 1]) * i;
			printf("%d %d\n", n, result);
		}
	}

	return 0;
}

