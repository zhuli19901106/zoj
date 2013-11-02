#include <algorithm>
#include <iostream>

int comparator(const void *a, const void *b)
{
	return *((int *)a) > *((int *)b);
}

using namespace std;

int main()
{
	int a[200];
	int i;
	int n;
	int sum;

	while(1)
	{
		cin>>n;
		if(n == 0)
		{
			break;
		}

		for(i = 0; i < n; i++)
		{
			cin>>a[i];
		}

		qsort(a, n, sizeof(int), comparator);
		sum = 0;
		for(i = 1; i < n - 1; i++)
		{
			sum = sum + a[i];
		}

		cout<<sum / (n - 2)<<endl;
	}	

	return 0;
}

