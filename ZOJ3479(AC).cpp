#include <stdio.h>

int main()
{
	int i;
	int n;
	int a;
	char zodiac[12][20] = {
		"Rat",
		"Ox",
		"Tiger",
		"Rabbit",
		"Dragon",
		"Snake",
		"Horse",
		"Ram",
		"Monkey",
		"Rooster",
		"Dog",
		"Pig"
	};

	while(1)
	{
		if(scanf("%d", &n) != 1)
		{
			break;
		}

		for(i = 0; i < n; i++)
		{
			scanf("%d", &a);
			a = a % 12;
			a = (16 - a) % 12;
			puts(zodiac[a]);
		}
	}

	return 0;
}

