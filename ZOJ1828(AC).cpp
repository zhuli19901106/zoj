#include <stdio.h>
#include <string.h>

#define MAXLEN 1005

void addup(int a[], int b[], int c[])
{
	int i;
	int maxdigit;

	maxdigit = MAXLEN - 1;
	while(maxdigit >= 0 && a[maxdigit] == 0 && b[maxdigit] == 0)
	{
		maxdigit--;
	}
	if(maxdigit == -1)
	{
		return;
	}

	for(i = 0; i <= maxdigit; i++)
	{
		c[i] = a[i] + b[i];
	}

	for(i = 0; i <= maxdigit; i++)
	{
		if(c[i] > 9)
		{
			c[i] = c[i] - 10;
			c[i + 1]++;
		}
	}
}

void PrintDigit(int a[])
{
	int i;
	int maxdigit;

	maxdigit = MAXLEN - 1;
	while(maxdigit >= 0 && a[maxdigit] == 0)
	{
		maxdigit--;
	}
	if(maxdigit == -1)
	{
		printf("0");
	}
	else
	{
		for(i = maxdigit; i >= 0; i--)
		{
			printf("%d", a[i]);
		}
	}
}

int main()
{
	int a[MAXLEN];
	int b[MAXLEN];
	int c[MAXLEN];
	int i;
	int n;

	while(1)
	{
		for(i = 0; i < MAXLEN; i++)
		{
			a[i] = 0;
			b[i] = 0;
			c[i] = 0;
		}
		a[0] = 1;
		b[0] = 1;

		if(scanf("%d", &n) != 1)
		{
			break;
		}

		if(n == 1 || n == 2)
		{
			printf("1\n");
		}
		else
		{
			for(i = 3; i <= n; i++)
			{
				switch(i % 3)
				{
				case 0:
					addup(a, b, c);
					if(i == n)
					{
						PrintDigit(c);
						printf("\n");
					}
					break;
				case 1:
					addup(b, c, a);
					if(i == n)
					{
						PrintDigit(a);
						printf("\n");
					}
					break;
				case 2:
					addup(c, a, b);
					if(i == n)
					{
						PrintDigit(b);
						printf("\n");
					}
					break;
				}
			}
		}
	}

	return 0;
}

