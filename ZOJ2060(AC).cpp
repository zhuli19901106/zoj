#include <stdio.h>
#include <stdlib.h>

int main()
{
	long *fib;
	long n;
	long i;

	fib = (long *)malloc(1000005 * sizeof(long));
	fib[0] = 7 % 3;
	fib[1] = 11 % 3;
	for(i = 2; i <= 1000000; i++)
	{
		fib[i] = (fib[i - 2] + fib[i - 1]) % 3;
	}

	while(1)
	{
		if(scanf("%ld", &n) != 1)
		{
			break;
		}

		if(fib[n] == 0)
		{
			printf("yes\n");
		}
		else
		{
			printf("no\n");
		}
	}

	free(fib);

	return 0;
}

