#include <algorithm>
#include <cstdio>
using namespace std;

typedef struct ST{
	int i;
	long n;
};

int comparator(const void *a, const void *b)
{
	return ((ST *)a)->n - ((ST *)b)->n;
}

int main()
{
	int t;
	int n;
	int i;
	int j;
	ST a[110];

	scanf("%d", &t);
	for(i = 0; i < t; i++)
	{
		scanf("%d", &n);
		for(j = 0; j < n; j++)
		{
			scanf("%ld", &a[j].n);
			a[j].i = j + 1;
		}

		qsort(a, n, sizeof(ST), comparator);
		printf("%d %ld\n", a[n - 1].i, a[n - 2].n);
	}

	return 0;
}

