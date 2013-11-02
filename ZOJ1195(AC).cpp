#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

int main()
{
	int i;
	int n;
	int m;
	int c;
	int d[30];
	int s[30];
	int p;
	int blow;
	int maxp;
	int t;
	int cc;

	cc = 0;
	while(scanf("%d%d%d", &n, &m, &c) == 3)
	{
		if(n == 0 && m == 0 && c == 0)
		{
			break;
		}

		for(i = 0; i < n; i++)
		{
			scanf("%d", &d[i]);
		}

		for(i = 0; i < n; i++)
		{
			s[i] = 0;
		}
		p = 0;
		maxp = 0;
		blow = 0;

		for(i = 0; i < m; i++)
		{
			scanf("%d", &t);
			
			if(s[t - 1] == 0)
			{
				p = p + d[t - 1];
				if(p > maxp)
				{
					maxp = p;
				}

				if(p > c)
				{
					blow = 1;
				}
			}
			else
			{
				p = p - d[t - 1];
			}
			s[t - 1] = !s[t - 1];
		}

		printf("Sequence %d\n", cc + 1);
		if(blow == 1)
		{
			printf("Fuse was blown.\n");
		}
		else
		{
			printf("Fuse was not blown.\n");
			printf("Maximal power consumption was %d amperes.\n", maxp);
		}

		printf("\n");
		cc++;
	}

	return 0;
}

