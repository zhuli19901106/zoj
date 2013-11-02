#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iterator>
#include <vector>
using namespace std;

int comparator(const void *a, const void *b)
{
	return *((int *)a) > *((int *)b);
}

int main()
{
	int n;
	int m;
	int i;
	int tmp;
	vector<int> a;
	int count;
	int fake;

	while(1)
	{
		scanf("%d%d", &n, &m);
		if(n == 0 && m == 0)
		{
			break;
		}

		for(i = 0; i < m; i++)
		{
			scanf("%d", &tmp);
			a.push_back(tmp);
		}

		sort(a.begin(), a.end());
		count = 0;
		i = 0;
		fake = 0;
		while(i < m - 1)
		{
			if(a[i] == a[i + 1])
			{
				if(fake == 0)
				{
					count++;
					fake = 1;
				}
			}
			else
			{
				if(fake == 1)
				{
					fake = 0;
				}
			}
			i++;
		}

		printf("%d\n", count);
		a.clear();
	}

	return 0;
}

