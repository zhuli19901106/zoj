#include <stdio.h>

int main()
{
	int r[105][105];
	int g[105][105];
	int b[105][105];
	int gray[105][105];
	int n;
	int m;
	int i;
	int j;
	int casecounter;

	casecounter = 0;
	while(1)
	{
		scanf("%d%d", &n, &m);
		if(n == 0 && m == 0)
		{
			break;
		}
		else
		{
			casecounter++;
		}

		for(i = 1; i <= n; i++)
		{
			for(j = 1; j <= m; j++)
			{
				scanf("%d", &r[i][j]);
			}
		}

		for(i = 1; i <= n; i++)
		{
			for(j = 1; j <= m; j++)
			{
				scanf("%d", &g[i][j]);
			}
		}

		for(i = 1; i <= n; i++)
		{
			for(j = 1; j <= m; j++)
			{
				scanf("%d", &b[i][j]);
			}
		}

		for(i = 1; i <= n; i++)
		{
			for(j = 1; j <= m; j++)
			{
				gray[i][j] = (r[i][j] + g[i][j] + b[i][j]) / 3;
			}
		}

		printf("Case %d:\n", casecounter);
		for(i = 1; i <= n; i++)
		{
			for(j = 1; j <= m; j++)
			{
				if(j == 1)
				{
					printf("%d", gray[i][j]);
				}
				else
				{
					printf(",%d", gray[i][j]);
				}
			}
			printf("\n");
		}
	}

	return 0;
}

