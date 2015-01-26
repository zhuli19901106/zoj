#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXN = 300;
char a[MAXN][MAXN];
int m, n;
char s[] = "BJHYN";

int main()
{
	int i, j;
	int t, ti;
	int res;
	int r1, r2, c;

	while(scanf("%d", &t) == 1){
		for(ti = 0; ti < t; ++ti){
			scanf("%d%d", &m, &n);
			for(i = 0; i < m; ++i){
				scanf("%s", a[i]);
			}

			res = 0;
			for(r1 = 0; r1 < m - 1; ++r1){
				for(r2 = r1 + 1; r2 < m; ++r2){
					for(j = 0; j < 5; ++j){
						i = 0;
						for(c = 0; c < n; ++c){
							if(a[r1][c] == a[r2][c] && a[r1][c] == s[j]){
								++i;
							}
						}
						res += i * (i - 1) / 2;
					}
				}
			}

			printf("%d\n", res);
		}
	}

	return 0;
}
