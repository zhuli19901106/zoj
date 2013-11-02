#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

int double_comparator(const void *a, const void *b)
{
	return *(double *)a > *(double *)b;
}

int main()
{
	int t;
	int ti;
	int i;
	int n;
	double a[1000];

	scanf("%d", &t);
	for(ti = 0; ti < t; ti++){
		scanf("%d", &n);
		for(i = 0; i < n; i++){
			scanf("%lf", &a[i]);
		}

		qsort(a, n, sizeof(double), double_comparator);
		if(n % 2 == 0){
			printf("%0.3f\n", (a[n / 2] + a[n / 2 - 1]) / 2.0);
		}else{
			printf("%0.3f\n", a[(n - 1) / 2]);
		}
	}

	return 0;
}

