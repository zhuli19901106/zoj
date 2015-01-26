#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

int comp(const void *a, const void *b)
{
	return *(const long long int *)a < *(const long long int *)b;
}

int main()
{
	long long int sum;
	long long int a[20005];
	int n;
	int i;
	int t, ti;
	
	while(true){
		if(scanf("%d", &t) != 1){
			break;
		}
		
		for(ti = 0; ti < t; ++ti){
			scanf("%d", &n);
			for(i = 0; i < n; ++i){
				scanf("%lld", &a[i]);
			}
			qsort(a, n, sizeof(long long int), comp);
			sum = 0;
			for(i = 2; i < n; i += 3){
				sum += a[i];
			}
			printf("%lld\n", sum);
		}
	}
	
	return 0;
}
