#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int a[1000];
int s[1000];
int n, m;
int res;

int main()
{
	int t, ti;
	int i;

	while(scanf("%d", &t) == 1){
		for(ti = 0; ti < t; ++ti){
			scanf("%d%d", &n, &m);
			for(i = 1; i <= n; ++i){
				scanf("%d", &a[i]);
			}
			for(i = n + 1; i <= 2 * n; ++i){
				a[i] = a[i - n];
			}
			s[0] = 0;
			for(i = 1; i <= 2 * n; ++i){
				s[i] = s[i - 1] + a[i];
			}
			res = s[m] - s[0];
			for(i = 1; i <= n; ++i){
				if(res < s[m + i] - s[i]){
					res = s[m + i] - s[i];
				}
			}
			printf("%d\n", res);
		}
	}

	return 0;
}
