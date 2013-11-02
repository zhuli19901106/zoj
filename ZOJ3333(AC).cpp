#include <stdio.h>

int main()
{
	int t;
	int ti;
	int a;
	int b;
	int p;

	scanf("%d", &t);
	for(ti = 0; ti < t; ti++)
	{
		scanf("%d%d%d", &p, &a, &b);
		a = a - p;
		b = b - p;
		if(a < 0)
		{
			a = -a;
		}
		if(b < 0)
		{
			b = -b;
		}
		if(a < b)
		{
			printf("A\n");
		}
		else
		{
			printf("B\n");
		}
	}

	return 0;
}

