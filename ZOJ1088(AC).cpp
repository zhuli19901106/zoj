#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

int main()
{
	int n;
	int m;
	int i;
	int j;
	int a[200];
	int count;
	int step;

	while(scanf("%d", &n) == 1)
	{
		if(n == 0)
		{
			break;
		}

		for(m = 2; ; m++)
		{
			for(i = 0; i < n; i++)
			{
				a[i] = 1;
			}
			count = n;

			j = 0;
			a[j] = 0;
			count--;
			step = 0;
			while(count > 1)
			{
				j++;
				if(j >= n)
				{
					j = j - n;
				}

				if(a[j] == 1)
				{
					step++;
				}

				if(step == m)
				{
					a[j] = 0;
					count--;
					step = 0;
				}
			}

			if(a[1] == 1)
			{
				printf("%d\n", m);
				break;
			}
		}
	}

	return 0;
}

