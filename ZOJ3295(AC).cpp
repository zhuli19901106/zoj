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
	int a[2000];
	int n;
	int k;
	int i;
	int ans;
	int key;
	int ikey;
	int tn;
	int base;

	while(scanf("%d%d", &n, &k) == 2){
		tn = 1 << n;
		for(i = 0; i < tn; i++){
			scanf("%d", &a[i]);
		}
		key = a[k];
		qsort(a, tn, sizeof(int), comparator);

		ikey = 0;
		while(a[ikey] != key){
			ikey++;
		}

		if(ikey == tn - 1){
			printf("%d %d\n", n, n);
		}else{
			ikey++;
			i = 0;
			
			while(true){
				ikey = ikey / 2;
				if(ikey > 0){
					i++;
				}else{
					break;
				}
			}

			printf("%d %d\n", 0, i);
		}
	}

	return 0;
}

