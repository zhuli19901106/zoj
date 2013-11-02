#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

int comparator(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int main()
{
	int i;
	int j;
	int n;
	int *a = NULL;
	const int bound = 2147483647;

	a = (int *)malloc(50000 * sizeof(int));
	if(a == NULL){
		fprintf(stderr, "Failed to allocate memory.\n");
		exit(1);
	}

	n = 0;
	for(i = 2; i <= 31; i++){
		for(j = 2; j <= pow(bound, 1.0 / i); j++){
			a[n] = (int)pow(1.0 * j, i);
			n++;
		}
	}

	qsort(a, n, sizeof(int), comparator);
	i = 0;
	while(i < n){
		printf("%d\n", a[i]);
		j = i + 1;
		while(j < n && a[j] == a[i]){
			j++;
		}
		i = j;
	}

	free(a);
	a = NULL;

	return 0;
}

