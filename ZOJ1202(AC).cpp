#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
using namespace std;

int P(int n, int k)
{
	int i;
	int sum;

	if(k == 0)
	{
		return 1;
	}
	else
	{
		sum = 1;
		for(i = 0; i < k; i++)
		{
			sum *= n - i;
		}

		return sum;
	}
}

int C(int n, int k)
{
	if(k == 0)
	{
		return 1;
	}
	else if(k >= n / 2 + 1)
	{
		return C(n, n - k);
	}
	else
	{
		return P(n, k) / P(k, k);
	}
}

int comparator(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int main()
{
	int i;
	int a[100];
	int n;
	int L, R;
	int sum;
	int partial_sum;

	int result;
	
	while(true)
	{
		if(scanf("%d", &n) != 1)
		{
			break;
		}
		
		sum = 0;
		for(i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
			sum += a[i];
		}
		
		qsort(a, n, sizeof(int), comparator);
		result = 1;
		L = 0;
		while(L < n)
		{
			R = L + 1;
			while(R < n && a[L] == a[R])
			{
				R++;
			}
			
			partial_sum = 1;
			for(i = L; i < R; i++)
			{
				partial_sum *= C(sum, a[i]);
				sum -= a[i];
			}
			partial_sum /= P(R - L, R - L);
			result *= partial_sum;
			L = R;
		}
		
		printf("%d\n", result);
	}
	
	return 0;
}

