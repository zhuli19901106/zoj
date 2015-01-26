#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXN = 10005;
int rp, ri;
int n;
double L, T;
double v[MAXN];
double res;

bool comparator(const double &a, const double &b)
{
	return a > b;
}

int main()
{
	int i;

	while(scanf("%d", &rp) == 1){
		for(ri = 1; ri <= rp; ++ri){
			scanf("%d%lf%lf", &n, &T, &L);
			for(i = 0; i < n; ++i){
				scanf("%lf", &v[i]);
			}
			sort(v, v + n, comparator);

			res = 0.0;
			for(i = 0; i < n; ++i){
				if(L > v[i] * T){
					L -= v[i] * T;
					res += T;
				}else{
					res += L / v[i];
					L = 0;
					break;
				}
			}

			if(L <= 0){
				printf("%.2f\n", res);
			}else{
				printf("-1\n");
			}
		}
	}

	return 0;
}
