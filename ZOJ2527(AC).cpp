#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

int comp(const void *a, const void *b)
{
	return *(const int *)a - *(const int *)b;
}

int main()
{
	int a[2000];
	int i, j, k;
	int df, n, tmp;
	int max_len, len;
	
	while(true){
		if(scanf("%d", &n) != 1){
			break;
		}
		for(i = 0; i < n; ++i){
			scanf("%d", &a[i]);
		}
		qsort(a, n, sizeof(int), comp);
		if(n <= 2){
			printf("%d\n", n);
			continue;
		}
		max_len = 2;
		for(i = 0; i < n - 1; ++i){
			for(j = i + 1; j < n; ++j){
				len = 2;
				df = a[j] - a[i];
				tmp = a[j];
				for(k = j + 1; k < n; ++k){
					if(a[k] - tmp > df){
						break;
					}else if(a[k] - tmp == df){
						++len;
						tmp = a[k];
					}
				}
				if(max_len < len){
					max_len = len;
				}
			}
		}
		
		printf("%d\n", max_len);
	}
	
	return 0;
}
