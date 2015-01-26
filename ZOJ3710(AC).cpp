//Accepted, BRUTE FORCE SIMULATION
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

const int MAXN = 105;
int a[MAXN][MAXN];
int c[MAXN][MAXN];
int fc;
int n, m, nk;
int res;

void myswap(int &x, int &y)
{
	int t;

	t = x;
	x = y;
	y = t;
}

int main()
{
	int t, ti;
	int x, y;
	int i, j, k;
	vector<int> v;

	while(scanf("%d", &t) == 1){
		for(ti = 0; ti < t; ++ti){
			scanf("%d%d%d", &n, &m, &nk);
			memset(a, 0, MAXN * MAXN * sizeof(int));
			for(i = 0; i < m; ++i){
				scanf("%d%d", &x, &y);
				if(x > y){
					myswap(x, y);
				}
				a[x][y] = 1;
			}

			res = 0;
			while(true){
				fc = 0;
				memset(c, 0, MAXN * MAXN * sizeof(int));
				for(i = 0; i < n; ++i){
					v.clear();
					for(j = 0; j < n; ++j){
						if(a[i][j] || a[j][i]){
							v.push_back(j);
						}
					}
					for(j = 0; j < (int)v.size(); ++j){
						for(k = j + 1; k < (int)v.size(); ++k){
							++c[v[j]][v[k]];
						}
					}
				}
				for(i = 0; i < n; ++i){
					for(j = i + 1; j < n; ++j){
						if(!a[i][j] && c[i][j] >= nk){
							a[i][j] = 1;
							++fc;
						}
					}
				}

				if(!fc){
					break;
				}else{
					res += fc;
				}
			}

			printf("%d\n", res);
		}
	}

	return 0;
}
