#include <stdio.h>

int main()
{
	int i;
	int a[10000];
	int sum[10000];
	int rem[5000];
	int n;
	int m;
	int count;

	while(1)
	{
		if(scanf("%d%d", &n, &m) != 2)
		{
			break;
		}

		count = 0;
		for(i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
			a[i] = a[i] % m;
			if(i == 0)
			{
				sum[i] = a[i];
			}
			else
			{
				sum[i] = (sum[i - 1] + a[i]) % m;
				if(sum[i] == 0)
				{
					count++;
				}
			}
		}

		for(i = 0; i < m; i++)
		{
			rem[i] = 0;
		}

		for(i = 0; i < n; i++)
		{
			rem[sum[i]]++;
		}

		for(i = 0; i < m; i++)
		{
			if(rem[i] > 1)
			{
				count = count + (rem[i]) * (rem[i] - 1) / 2;
			}
		}

		printf("%d\n", count);
	}

	return 0;
}

