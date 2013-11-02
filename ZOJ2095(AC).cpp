#include <cmath>
#include <cstdio>
using namespace std;

int main()
{
	int t;
	int n;
	int ti;
	int i;
	int rt;
	int sum;

	while(1)
	{
		if(scanf("%d", &t) != 1)
		{
			break;
		}

		for(ti = 0; ti < t; ti++)
		{
			scanf("%d", &n);
			if(n == 1)
			{
				printf("0\n");
				continue;
			}
			rt = sqrt(1.0 * n);
			sum = 1;
			for(i = 2; i <= rt; i++)
			{
				if(n % i == 0)
				{
					if(i * i == n)
					{
						sum = sum + i;
					}
					else
					{
						sum = sum + i + n / i;
					}
				}
			}

			printf("%d\n", sum);
		}
	}

	return 0;
}

