#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXN = 501;
int a[MAXN][MAXN];
int b[MAXN][MAXN];
int n;

int main()
{
	int i, j;
	int ti;

	ti = 0;
	while(scanf("%d", &n) == 1 && n){
		++ti;
		memset(a, 0, MAXN * MAXN * sizeof(int));
		for(i = 1; i <= n; ++i){
			for(j = 1; j <= n; ++j){
				scanf("%d", &a[i][j]);
			}
		}
		memcpy(b, a, MAXN * MAXN * sizeof(int));
		for(i = 2; i <= n - 1; ++i){
			for(j = 2; j <= n - 1; ++j){
				b[i][j] = 0;
				b[i][j] += (a[i - 1][j - 1] + a[i - 1][j + 1] + a[i + 1][j - 1] + a[i + 1][j + 1]);
				b[i][j] += 2 * (a[i - 1][j] + a[i + 1][j] + a[i][j - 1] + a[i][j + 1]);
				b[i][j] += 4 * a[i][j];
				b[i][j] /= 16;
			}
		}

		printf("Case %d:\n", ti);
		for(i = 1; i <= n; ++i){
			for(j = 1; j <= n; ++j){
				if(j == 1){
					printf("%d", b[i][j]);
				}else{
					printf(" %d", b[i][j]);
				}
			}
			printf("\n");
		}
	}

	return 0;
}
