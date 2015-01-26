#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

int comp(const void *a, const void * b)
{
	return *((const int *)a) - *((const int *)b);
}

int bsearch(const int a[], const int n, const int key)
{
	int left;
	int mid;
	int right;

	left = 0;
	right = n - 1;
	while(left <= right){
		mid = (left + right) / 2;
		if(a[mid] == key){
			return mid;
		}else if(a[mid] > key){
			right = mid - 1;
		}else{
			left = mid + 1;
		}
	}

	return -1;
}

int main()
{
	int n;
	int i, j, k;
	int sum;
	int a[2000];
	bool has_solution;
	int winner;
	
	while(true){
		scanf("%d", &n);
		if(0 == n){
			break;
		}
		for(i = 0; i < n; ++i){
			scanf("%d", &a[i]);
		}
		qsort(a, n, sizeof(int), comp);
		winner = -1;
		has_solution = false;
		for(i = n - 1; !has_solution && i >= 0; --i){
			for(j = 0; !has_solution && j < n - 1; ++j){
				if(i == j){
					continue;
				}
				for(k = j + 1; !has_solution && k < n; ++k){
					if(k == i){
						continue;
					}
					sum = a[i] - a[j] - a[k];
					if(sum == a[i] || sum == a[j] || sum == a[k]){
						continue;
					}else{
						if(-1 != bsearch(a, n, sum)){
							has_solution = true;
							winner = a[i];
						}
					}
				}
			}
		}

		if(!has_solution){
			printf("no solution\n");
		}else{
			printf("%d\n", winner);
		}
	}
	
	return 0;
}
