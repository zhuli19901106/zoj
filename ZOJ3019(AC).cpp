#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int max(int a, int b)
{
	return (a > b ? a : b);
}

int comparator(const void *a, const void *b)
{
	return *((int *)a) > *((int *)b);
}

int main()
{
	int na;
	int nb;
	int *a;
	int *b;
	int i;
	int j;
	int *f[2];
	int now;

	a = (int *)malloc(11000 * sizeof(int));
	b = (int *)malloc(11000 * sizeof(int));
	f[0] = (int *)malloc(11000 * sizeof(int));
	f[1] = (int *)malloc(11000 * sizeof(int));

	while(1)
	{
		if(scanf("%d%d", &na, &nb) != 2)
		{
			break;
		}

		for(i = 0; i < na; i++)
		{
			scanf("%d", &a[i]);
		}

		for(i = 0; i < nb; i++)
		{
			scanf("%d", &b[i]);
		}

		qsort(a, na, sizeof(int), comparator);
		qsort(b, nb, sizeof(int), comparator);

		memset(f[0], 0, 11000 * sizeof(int));
		memset(f[1], 0, 11000 * sizeof(int));

		now = 0;
		for(i = 0; i < na; i++)
		{
			for(j = 0; j < nb; j++)
			{
				if(a[i] == b[j])
				{
					f[now][j + 1] = f[!now][j] + 1;
				}
				else
				{
					f[now][j + 1] = max(f[now][j], f[!now][j + 1]);
				}
			}
			now = !now;
		}

		printf("%d\n", f[!now][nb]);
	}

	free(a);
	free(b);
	free(f[0]);
	free(f[1]);

	return 0;
}

