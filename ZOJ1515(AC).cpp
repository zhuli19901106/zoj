#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef long long int LL;

LL combination(LL n, LL k)
{
	LL res, rem;
	LL i;

	if(k > n / 2){
		return combination(n, n - k);
	}

	res = rem = 1;
	for(i = 1; i <= k; ++i){
		res *= (n + 1 - i);
		if(res % i){
			rem *= i;
		}else{
			res /= i;
		}
		if(res % rem == 0){
			res /= rem;
			rem = 1;
		}
	}

	return res;
}

int n, p;
LL c[101];

inline bool inbound(int a, int b, int n)
{
	return (a >= 1 && a <= n) && (b >= 1 && b <= n);
}

LL count_square(int n)
{
	int i;
	LL res;

	//grid squares
	res = (n - 1) * (n) * (2 * n - 1) / 6;
	for(i = 3; i <= n; ++i){
		res += (i - 2) * (n - i + 1) * (n - i + 1);
	}

	return res;
}

int main()
{
	int i;

	for(i = 2; i <= 100; ++i){
		c[i] = count_square(i);
	}

	while(scanf("%d%d", &n, &p) == 2 && (n || p)){
		printf("%.2f\n", p / 100.0 * combination(n * n, 4) / c[n]);
	}

	return 0;
}
