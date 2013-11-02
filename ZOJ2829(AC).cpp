#include <stdio.h>
#include <stdlib.h>
#define MAXN 100000

int main()
{
	int *a;
	int i3;
	int i5;
	int count;
	int n;

	a = (int *)malloc(MAXN * sizeof(int));

	count = 0;
	i3 = 3;
	i5 = 5;
	while(count < MAXN)
	{
		if(i3 < i5)
		{
			a[count] = i3;
			count++;
			i3 = i3 + 3;
		}
		else if(i3 == i5)
		{
			a[count] = i3;
			count++;
			i3 = i3 + 3;
			i5 = i5 + 5;
		}
		else
		{
			a[count] = i5;
			count++;
			i5 = i5 + 5;
		}
	}

	while(1)
	{
		if(scanf("%d", &n) != 1)
		{
			break;
		}
		else
		{
			printf("%d\n", a[n - 1]);
		}
	}
	free(a);

	return 0;
}

