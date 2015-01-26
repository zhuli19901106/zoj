#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int a[25][25][25];
int b[25][25][25];
int c[25];
int n;
int res;

int max_sum(const int c[], const int n)
{
	int i, s, maxs;

	s = 0;
	maxs = 0;
	for(i = 1; i <= n; ++i){
		s += c[i];
		if(s < 0){
			s = 0;
		}
		if(s > maxs){
			maxs = s;
		}
	}

	return maxs;
}

int main()
{
	int i, j, k;
	int j1, k1, j2, k2;
	int tmp;

	while(scanf("%d", &n) == 1 && n){
		res = -99999;
		memset(a, 0, 25 * 25 * 25 * sizeof(int));
		for(i = 1; i <= n; ++i){
			for(j = 1;j <= n; ++j){
				for(k = 1; k <= n; ++k){
					scanf("%d", &a[i][j][k]);
					if(a[i][j][k] > res){
						res = a[i][j][k];
					}
				}
			}
		}

		if(res <= 0){
			printf("%d\n", res);
			continue;
		}

		memset(b, 0, 25 * 25 * 25 * sizeof(int));
		for(i = 1; i <= n; ++i){
			for(j = 1; j <= n; ++j){
				for(k = 1; k <= n; ++k){
					b[i][j][k] = b[i][j][k - 1] + b[i][j - 1][k] + a[i][j][k] - b[i][j - 1][k - 1];
				}
			}
		}

		res = -99999;
		for(j1 = 1; j1 <= n; ++j1){
			for(k1 = 1; k1 <= n; ++k1){
				for(j2 = j1; j2 <= n; ++j2){
					for(k2 = k1; k2 <= n; ++k2){
						for(i = 1; i <= n; ++i){
							c[i] = b[i][j2][k2] - (b[i][j1 - 1][k2] + b[i][j2][k1 - 1] - b[i][j1 - 1][k1 - 1]);
						}
						tmp = max_sum(c, n);
						if(tmp > res){
							res = tmp;
						}
					}
				}
			}
		}

		printf("%d\n", res);
	}

	return 0;
}
