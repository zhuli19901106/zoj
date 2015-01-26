#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
typedef long long int LL;
LL prime[15] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
LL ans[100000];
int ac;

typedef struct st{
	int i;
	LL v;
}st;

st b[20];
int bc;
LL min_v;
LL max_pro;
int c[100];

void dfs(int ci, int eu, LL sum, LL n, LL pro)
{
	int i;

	if(ci >= 15){
		return;
	}

	if(sum > n){
		return;
	}

	if(max_pro < pro){
		max_pro = pro;
		min_v = sum;
	}else if(max_pro == pro){
		if(min_v > sum){
			min_v = sum;
		}
	}

	for(i = 1; i <= eu; ++i){
		sum *= prime[ci];
		c[ci] = i;
		if(sum > n){
			break;
		}else{
			dfs(ci + 1, i, sum, n, pro * (c[ci] + 1));
		}
	}
}

int main()
{
	LL n;

	while(true){
		if(scanf("%lld", &n) != 1){
			break;
		}else{
			if(n <= 1){
				printf("%lld\n", n);
			}else{
				max_pro = 1;
				min_v = 1;
				dfs(0, 60, 1, n, 1);
				printf("%lld\n", min_v);
			}
		}
	}
	
	return 0;
}
