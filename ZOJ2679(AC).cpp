#include <stdio.h>

int main()
{
	int i;
	int j;
	int k;
	int x;
	int y;
	int z;
	int d1;
	int d2;
	int n;
	int t;
	int end;
	long total;
	long price;

	scanf("%d", &t);
	for(k = 0; k < t; k++)
	{
		scanf("%d", &n);
		scanf("%d%d%d", &x, &y, &z);

		price = 0;
		end = 0;
		for(i = 9; end == 0 && i >= 1; i--)
		{
			for(j = 9; end == 0 && j >= 0; j--)
			{
				total = i * 10000 + x * 1000 + y * 100 + z * 10 + j;
				if(total % n == 0)
				{
					price = total / n;
					d1 = i;
					d2 = j;
					end = 1;
				}
			}
		}

		if(price != 0)
		{
			printf("%d %d %ld\n", d1, d2, price);
		}
		else
		{
			printf("0\n");
		}
	}

	return 0;
}

