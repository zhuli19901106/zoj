#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

int main()
{
	int ti;
	int t;

	int i;
	int j;
	int n;
	int k;

	int tmp;

	int a[10001];
	int dp[2][101];
	int an;

	int flag;

	scanf("%d", &t);
	for(ti = 0; ti < t; ti++)
	{
		if(ti != 0)
		{
			printf("\n");
		}

		an = 0;

		scanf("%d%d", &n, &k);
		for(i = 0; i < n; i++)
		{
			scanf("%d", &tmp);
			if(tmp < 0)
			{
				tmp = -tmp;
			}

			tmp = tmp % k;
			if(tmp > 0)
			{
				a[an] = tmp;
				an++;
			}
		}

		if(an == 0)
		{
			printf("Divisible\n");
			continue;
		}

		for(i = 0; i < 2; i++)
		{
			for(j = 0; j < k; j++)
			{
				dp[i][j] = 0;
			}
		}

		flag = 0;
		dp[flag][a[0] % k] = 1;
		dp[flag][k - (a[0] % k)] = 1;

		for(i = 1; i < an; i++)
		{
			flag = !flag;
			for(j = 0; j < k; j++)
			{
				dp[flag][j] = 0;
			}

			for(j = 0; j < k; j++)
			{
				if(dp[flag][(k + j - a[i]) % k] == 0)
				{
					dp[flag][(k + j - a[i]) % k] = dp[!flag][j];
				}

				if(dp[flag][(j + a[i]) % k] == 0)
				{
					dp[flag][(j + a[i]) % k] = dp[!flag][j];
				}
			}
		}

		if(dp[flag][0] == 1)
		{
			printf("Divisible\n");
		}
		else
		{
			printf("Not divisible\n");
		}
	}

	return 0;
}

