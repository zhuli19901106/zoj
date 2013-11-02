#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

const int MAXN = 505;
int cc;
int n, m;
int a[MAXN][MAXN];
vector<int> vx, vy;

int main()
{
	int t, ti;
	int x, y;
	int i;

	while(scanf("%d", &t) == 1){
		for(ti = 0; ti < t; ++ti){
			scanf("%d%d", &n, &m);
			memset(a, 0, MAXN * MAXN * sizeof(int));
			cc = 0;

			vx.clear();
			for(i = 0; i < m; ++i){
				scanf("%d", &x);
				vx.push_back(x);
			}

			vy.clear();
			for(i = 0; i < m; ++i){
				scanf("%d", &y);
				vy.push_back(y);
			}

			for(i = 0; i < m; ++i){
				x = vx[i];
				y = vy[i];
				if(!a[x][y] && !a[y][x]){
					a[x][y] = a[y][x] = 1;
					++cc;
				}else{
					a[x][y] = a[y][x] = 1;
				}
			}
			printf("%.3f\n", 1.0 * cc / n);
		}
	}

	return 0;
}

