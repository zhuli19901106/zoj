#include <stdio.h>

int main()
{
	int i;
	int n;
	int a[1000];
	const int up = 6;
	const int down = 4;
	const int stop = 5;
	int current;
	int time;

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

		current = 0;
		time = 0;
		for(i = 0; i < n; i++)
		{
			if(a[i] > current)
			{
				time = time + (a[i] - current) * up + stop;
			}
			else if(a[i] == current)
			{
				time = time + stop;
			}
			else
			{
				time = time + (current - a[i]) * down + stop;
			}
			current = a[i];
		}

		printf("%d\n", time);
	}
	
	return 0;
}

