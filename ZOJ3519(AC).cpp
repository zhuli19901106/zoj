#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

int comparator(const void *a, const void *b)
{
	return *((int *)a) - *((int *)b);
}

int main()
{
	int a[1000];
	int n;
	int pivot;
	int count;
	int ip;
	int i;

	while(true){
		if(scanf("%d%d", &n, &ip) == 2){
			for(i = 0; i < n; i++){
				scanf("%d", &a[i]);
			}
			
			qsort(a, n, sizeof(int), comparator);
			count = 0;
			pivot = 0;
			while(true){
				while(pivot < n && a[pivot] <= ip){
					pivot++;
				}
				if(pivot == n){
					break;
				}

				ip = ip + 2;
				count++;
				pivot++;
			}
			ip = ip + n - count;

			printf("%d\n", ip);
		}else{
			break;
		}
	}

	return 0;
}

