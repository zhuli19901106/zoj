#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *a;
	int *b;
	int i;
	int j;
	int t;
	int ti;
	int count;
	int s1;
	int s2;

	a = (int *)malloc(1000000 * sizeof(int));
	b = (int *)malloc(1000000 * sizeof(int));

	scanf("%d", &t);
	for(ti = 0; ti < t; ti++)
	{
		scanf("%d", &s1);
		for(i = 0; i < s1; i++)
		{
			scanf("%d", &a[i]);
		}

		scanf("%d", &s2);
		for(i = 0; i < s2; i++)
		{
			scanf("%d", &b[i]);
		}

		i = 0;
		j = 0;
		count = 0;
		while(i < s1 && j < s2)
		{
			if(a[i] > b[j])
			{
				j++;
			}
			else if(a[i] == b[j])
			{
				count++;
				i++;
				j++;
			}
			else
			{
				i++;
			}
		}

		printf("%d\n", count);
	}

	return 0;
}

