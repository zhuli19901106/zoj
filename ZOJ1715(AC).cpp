#include <cstdio>
using namespace std;

int main()
{
	int n;
	int q;
	int date[100];
	int maxi;
	int i;
	int j;
	int d;
	int m;

	while(1)
	{
		scanf("%d%d", &n, &q);
		if(n == 0 && q == 0)
		{
			break;
		}
		else
		{
			for(i = 0; i < 100; i++)
			{
				date[i] = 0;
			}

			for(i = 0; i < n; i++)
			{
				scanf("%d", &m);
				for(j = 0; j < m; j++)
				{
					scanf("%d", &d);
					date[d]++;
				}
			}

			maxi = 0;
			for(i = 1; i < 100; i++)
			{
				if(date[i] > date[maxi])
				{
					maxi = i;
				}
			}

			if(date[maxi] < q)
			{
				printf("0\n");
			}
			else
			{
				printf("%d\n", maxi);
			}
		}
	}

	return 0;
}

