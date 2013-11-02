#include <stdio.h>
int a[12][12];

int main()
{
	int n;
	int m;
	int i;
	int j;
	int result;
	int count;

	while(1)
	{
		for(i = 0; i < 12; i++)
		{
			for(j = 0; j < 12; j++)
			{
				a[i][j] = 1;
			}
		}

		scanf("%d%d", &n, &m);
		if(n == 0 && m == 0)
		{
			break;
		}

		count = 0;
		for(i = 1; i <= n; i++)
		{
			for(j = 1; j <= m; j++)
			{
				scanf("%d", &a[i][j]);
				if(a[i][j] == 0)
				{
					count++;
				}
			}
		}

		if(count > 0)
		{
			result = 1;
			for(i = 1; result == 1 && i <= n; i++)
			{
				for(j = 1; result == 1 && j <= m; j++)
				{
					if(a[i][j] == 0)
					{
						if(a[i - 1][j] == 0 || a[i + 1][j] == 0)
						{
							result = 0;
						}
						else if(a[i][j - 1] == 0 || a[i][j + 1] == 0)
						{
							result = 0;
						}
					}
				}
			}
		}
		else
		{
			result = 0;
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

