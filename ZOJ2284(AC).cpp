#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

long long int f[21][200];

int main()
{
	int n, k, i;
	int limit1;
	
	memset(f, 0, 21 * 200 * sizeof(long long int));
	f[1][0] = 1;
	for(n = 2; n <= 20; ++n){
		limit1 = (n - 1) * (n - 2) / 2;
		for(k = 0; k <= limit1; ++k){
			for(i = 0; i < n; ++i){
				f[n][k + i] += f[n - 1][k];
			}
		}
	}
	
	while(true){
		if(scanf("%d%d", &n, &k) != 2){
			break;
		}else if(0 == n && 0 == k){
			break;
		}
		if(k > n * (n - 1) / 2){
			printf("0\n");
		}else{
			printf("%lld\n", f[n][k]);
		}
	}
	
	return 0;
}
