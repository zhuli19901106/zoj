#include <algorithm>
#include <cstdio>
using namespace std;

int comparator(const void *a, const void *b)
{
	return *((int *)a) > *((int *)b);
}

int main()
{
	int a[105];
	int b[105];
	int i;
	int j;
	int k;
	int n;

	while(1)
	{
		scanf("%d", &n);
		if(n == 0)
		{
			break;
		}

		for(i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
		}

		qsort(a, n, sizeof(int), comparator);

		i = 0;
		k = 0;
		j = i + 1;
		while(i < n)
		{
			while(a[i] == a[j])
			{
				j++;
			}
			b[k] = a[i];
			k++;
			i = j;
			j = i + 1;
		}

		for(i = 0; i < k; i++)
		{
			if(i == 0)
			{
				printf("%d", b[i]);
			}
			else
			{
				printf(" %d", b[i]);
			}
		}
		printf("\n");
	}

	return 0;
}

