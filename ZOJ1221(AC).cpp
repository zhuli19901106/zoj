#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
using namespace std;

#define INF 10000

int main()
{
	int a[30][30];
	int checked[30];
	int d[30];
	int src;
	int dst;
	bool terminate;
	int ts;
	int i;
	int j;
	int n;
	int tmp;
	queue<int> q;

	ts = 0;
	terminate = false;
	while(false == terminate)
	{
		terminate = false;
		for(i = 1; i <= 20; i++)
		{
			for(j = 1; j <= 20; j++)
			{
				a[i][j] = 0;
			}
		}

		for(i = 1; i < 20; i++)
		{
			if(scanf("%d", &n) != 1)
			{
				terminate = true;
				break;
			}
			
			for(j = 1; j <= n; j++)
			{
				scanf("%d", &tmp);
				a[i][tmp] = a[tmp][i] = 1;
			}
		}
		ts++;

		if(false == terminate)
		{
			printf("Test Set #%d\n", ts);
			scanf("%d", &n);
			for(i = 1; i <= n; i++)
			{
				scanf("%d%d", &src, &dst);

				for(j = 1; j <= 20; j++)
				{
					d[j] = INF;
					checked[j] = false;
				}

				d[src] = 0;
				q.push(src);
				checked[src] = true;
				while(q.size() > 0)
				{
					tmp = q.front();
					q.pop();
					for(j = 1; j <= 20; j++)
					{
						if(a[tmp][j] == 1 || a[j][tmp] == 1)
						{
							if(checked[j] == false)
							{
								d[j] = d[tmp] + 1;
								q.push(j);
								checked[j] = true;
							}
						}
					}
				}

				printf("%d to %d: %d\n", src, dst, d[dst]);
			}
			printf("\n");
		}
	}

	return 0;
}

