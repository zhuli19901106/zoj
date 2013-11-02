#include <algorithm>
#include <cstdio>
using namespace std;

int comparator(const void *a, const void *b)
{
	return (*(int *)a) > (*(int *)b);
}

int main()
{
	int b[1000];
	int a[15][15];
	int i;
	int j;
	int n;
	int n2;
	int result;
	int sum;
	int sum1;

	while(1)
	{
		scanf("%d", &n);
		if(n == 0)
		{
			break;
		}

		for(i = 1; i <= n; i++)
		{
			for(j = 1; j <= n; j++)
			{
				scanf("%d", &a[i][j]);
			}
		}

		for(i = 1; i <= n; i++)
		{
			for(j = 1; j <= n; j++)
			{
				b[(i - 1) * n + j] = a[i][j];
			}
		}
		qsort(b, n * n, sizeof(int), comparator);

		n2 = n * n;
		result = 1;
		for(i = 1; result == 1 && i < n2; i++)
		{
			if(b[i] == b[i + 1])
			{
				result = 0;
			}
		}
		
		for(i = 1; result == 1 && i <= n; i++)
		{
			if(i == 1)
			{
				sum = 0;
				for(j = 1; result == 1 && j <= n; j++)
				{
					sum = sum + a[i][j];
				}
			}
			else
			{
				sum1 = 0;
				for(j = 1; result == 1 && j <= n; j++)
				{
					sum1 = sum1 + a[i][j];
				}

				if(sum != sum1)
				{
					result = 0;
				}
			}
		}

		for(i = 1; result == 1 && i <= n; i++)
		{
			if(i == 1)
			{
				sum = 0;
				for(j = 1; result == 1 && j <= n; j++)
				{
					sum = sum + a[j][i];
				}
			}
			else
			{
				sum1 = 0;
				for(j = 1; result == 1 && j <= n; j++)
				{
					sum1 = sum1 + a[j][i];
				}

				if(sum != sum1)
				{
					result = 0;
				}
			}
		}

		if(result == 1)
		{
			sum1 = 0;
			for(i = 1; result == 1 && i <= n; i++)
			{
				sum1 = sum1 + a[i][i];
			}

			if(sum1 != sum)
			{
				result = 0;
			}
		}

		if(result == 1)
		{
			sum1 = 0;
			for(i = 1; result == 1 && i <= n; i++)
			{
				sum1 = sum1 + a[i][n + 1 - i];
			}

			if(sum1 != sum)
			{
				result = 0;
			}
		}

		if(result == 1)
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

