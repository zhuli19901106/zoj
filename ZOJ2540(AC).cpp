#include <algorithm>
#include <cstdio>
using namespace std;

int comparator(const void *a, const void *b)
{
	return (*(int *)a) > (*(int *)b);
}

int main()
{
	int i;
	int j;
	int k;
	int t;
	int ti;
	int a[4][2];
	int len[6];
	char buffer[1000];

	gets(buffer);
	sscanf(buffer, "%d", &t);
	for(ti = 1; ti <= t; ti++)
	{
		gets(buffer);
		for(i = 0; i < 4; i++)
		{
			gets(buffer);
			sscanf(buffer, "%d%d", &a[i][0], &a[i][1]);
		}

		k = 0;
		for(i = 0; i < 3; i++)
		{
			for(j = i + 1; j < 4; j++)
			{
				len[k] = (a[i][0] - a[j][0]) * (a[i][0] - a[j][0]) + (a[i][1] - a[j][1]) * (a[i][1] - a[j][1]);
				k++;
			}
		}
		qsort(len, 6, sizeof(int), comparator);

		printf("Case %d:\n", ti);
		if(len[0] == len[1] && len[1] == len[2] && len[2] == len[3] && len[3] < len[4] && len[4] == len[5])
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}

		if(ti != t)
		{
			printf("\n");
		}
	}

	return 0;
}

