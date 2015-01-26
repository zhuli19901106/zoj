#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef struct point
{
	int a;
	int b;
}Point;

int comp(const void *a, const void *b)
{
	return *(const int *)a - *(const int *)b;
}

int pcomp(const void *a, const void *b)
{
	const Point *pa, *pb;

	pa = (const Point *)a;
	pb = (const Point *)b;

	if(pa->b == pb->b){
		return pa->a - pb->a;
	}else{
		return pa->b - pb->b;
	}
}

int n, m;
int cube[51];
int hash[500000];
int sum[50000];
int sum_count;
int found_count;
Point res[10000];

int main()
{
	int i, j, k;
	int a, b;
	int num;
	int case_count;
	
	for(i = 0; i <= 50; ++i){
		cube[i] = i * i * i;
	}
	
	case_count = 0;
	while(scanf("%d%d", &n, &m) == 2 && (n != 0 || m != 0)){
		++case_count;
		if(case_count > 1){
			printf("\n");
		}
		printf("Case %d:\n", case_count);
		
		memset(hash, 0, 500000 * sizeof(int));
		k = 0;
		for(i = 0; i <= m; ++i){
			for(j = 0; j <= m; ++j){
				num = cube[i] + cube[j];
				if(!hash[num]){
					sum[k++] = num;
					hash[num] = 1;
				}
			}
		}
		sum_count = k;
		qsort(sum, sum_count, sizeof(int), comp);
		
		found_count = 0;
		for(i = 0; i < sum_count; ++i){
			for(j = i + 1; j < sum_count; ++j){
				a = sum[i];
				b = sum[j] - sum[i];
				for(k = 2; k < n; ++k){
					num = a + k * b;
					if(num > sum[sum_count - 1] || !hash[num]){
						break;
					}
				}
				if(k >= n){
					res[found_count].a = a;
					res[found_count].b = b;
					++found_count;
				}
			}
		}
		
		if(0 == found_count){
			printf("NONE\n");
		}else{
			qsort(res, found_count, sizeof(Point), pcomp);
			for(i = 0; i < found_count; ++i){
				printf("%d %d\n", res[i].a, res[i].b);
			}
		}
	}
	
	return 0;
}
