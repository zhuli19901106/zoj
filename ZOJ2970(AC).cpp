#include <stdio.h>
#include <string.h>

int main()
{
	int t;
	int ti;
	int n;
	int a[3000];
	int i;
	int min;
	int max;
	char type[100];

	scanf("%d", &t);
	for(ti = 0; ti < t; ti++)
	{
		scanf("%s", type);
		scanf("%d", &n);
		for(i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
			if(i == 0)
			{
				min = a[0];
				max = a[0];
			}
			else
			{
				if(a[i] < min)
				{
					min = a[i];
				}

				if(a[i] > max)
				{
					max = a[i];
				}
			}
		}

		if(strcmp(type, "Faster") == 0)
		{
			printf("%d\n", min);
		}
		else if(strcmp(type, "Higher") == 0)
		{
			printf("%d\n", max);
		}
		else if(strcmp(type, "Stronger") == 0)
		{
			printf("%d\n", max);
		}
	}

	return 0;
}

