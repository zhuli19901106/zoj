#include <stdio.h>

int main()
{
	int alt1[10000];
	int alt2[10000];
	int cost1;
	int cost2;
	int a[10000];
	int i;
	int n;

	for(i = 0; i < 10000; i++)
	{
		alt1[i] = i % 2;
		alt2[i] = (i + 1) % 2;
	}
	
	while(1)
	{
		if(scanf("%d", &n) != 1)
		{
			break;
		}

		cost1 = 0;
		cost2 = 0;
		for(i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
			if(a[i] != alt1[i])
			{
				cost1++;
			}
			if(a[i] != alt2[i])
			{
				cost2++;
			}
		}
		if(cost1 < cost2)
		{
			printf("%d\n", cost1);
		}
		else
		{
			printf("%d\n", cost2);
		}
	}

	return 0;
}

