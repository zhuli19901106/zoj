#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int comp(const void *a, const void *b)
{
	return *(const int *)a - *(const int *)b;
}

int sum[1000001];

int main()
{
	int i, j;
	int m;

	memset(sum, 0, 1000001 * sizeof(int));
	for(i = 1; i < 500001; ++i){
		for(j = i * 2; j < 1000001; j += i){
			sum[j] += i;
		}
	}
	
	qsort(sum, 1000001, sizeof(int), comp);
	
	while(true){
		if(scanf("%d", &m) != 1){
			break;
		}
		if(m < sum[1]){
			printf("0\n");
		}else if(m >= sum[1000000]){
			printf("1000000\n");
		}else{
			i = 1000000;
			while(sum[i] > m){
				--i;
			}
			printf("%d\n", i);
		}
	}

	return 0;
}

