#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef long long int LL;
LL res, n;

int main()
{
	int i;
	int t, ti;
	LL rt;

	while(scanf("%d", &t) == 1){
		for(ti = 0; ti < t; ++ti){
			scanf("%lld", &n);
			rt = (int)sqrt(1.0 * n);
			res = 0;
			for(i = 1; i <= rt; ++i){
				res += n / i - i + 1;
			}
			res = res * 2 - rt - n;
			printf("%lld\n", res);
		}
	}

	return 0;
}

