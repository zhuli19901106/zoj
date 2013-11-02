#include <math.h>
#include <stdio.h>

int main()
{
	int a;
	int b;
	int c;
	double da;
	double db;
	double dc;
	int counter;

	counter = 0;
	while(1)
	{
		scanf("%d%d%d", &a, &b, &c);
		if(a == 0 && b == 0 && c == 0)
		{
			break;
		}
		else
		{
			counter++;
		}

		printf("Triangle #%d\n", counter);
		if(a == -1)
		{
			if(c > b)
			{
				da = sqrt(1.0 * c * c - b * b);
				printf("a = %0.3f\n\n", da);
			}
			else
			{
				printf("Impossible.\n\n");
			}
		}
		else if(b == -1)
		{
			if(c > a)
			{
				db = sqrt(1.0 * c * c - a * a);
				printf("b = %0.3f\n\n", db);
			}
			else
			{
				printf("Impossible.\n\n");
			}
		}
		else if(c == -1)
		{
			dc = sqrt(1.0 * a * a + b * b);
			printf("c = %0.3f\n\n", dc);
		}
	}

	return 0;
}

