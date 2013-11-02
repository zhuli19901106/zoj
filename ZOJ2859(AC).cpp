#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef struct item{
	int value;
	int i;
	int j;
}Item;

int comparator(const void *a, const void *b)
{
	return ((Item *)a)->value > ((Item *)b)->value;
}

int contains(int i, int j, int i1, int j1, int i2, int j2)
{
	if(i1 > i2)
	{
		return contains(i, j, i2, j1, i1, j2);
	}
	else if(j1 > j2)
	{
		return contains(i, j, i1, j2, i2, j1);
	}
	else
	{
		return (i >= i1 && i <= i2) && (j >= j1 && j <= j2);
	}
}

int main()
{
	int a[302][302];
	Item *b;
	int qnum;
	int qi;
	int n;
	int n2;
	int i;
	int j;
	int i1;
	int i2;
	int j1;
	int j2;
	int t;
	int ti;

	b = (Item *)malloc(302 * 302 * sizeof(Item));
	scanf("%d", &t);
	for(ti = 0; ti < t; ti++)
	{
		scanf("%d", &n);
		n2 = n * n;
		for(i = 1; i <= n; i++)
		{
			for(j = 1; j <= n; j++)
			{
				scanf("%d", &a[i][j]);
				b[(i - 1) * n + (j - 1)].value = a[i][j];
				b[(i - 1) * n + (j - 1)].i = i;
				b[(i - 1) * n + (j - 1)].j = j;
			}
		}
		qsort(b, n2, sizeof(Item), comparator);

		scanf("%d", &qnum);
		for(qi = 0; qi < qnum; qi++)
		{
			scanf("%d%d%d%d", &i1, &j1, &i2, &j2);
			for(i = 0; i < n2; i++)
			{
				if(contains(b[i].i, b[i].j, i1, j1, i2, j2))
				{
					break;
				}
			}
			printf("%d\n", b[i].value);
		}
	}
	free(b);

	return 0;
}

