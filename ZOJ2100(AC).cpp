#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXN = 20;
char s[MAXN][MAXN];
int b[MAXN][MAXN];
int n, m;
bool suc;
int cc;
const int d[4][2] = {{-1, 0}, {+1, 0}, {0, -1}, {0, +1}};

void dfs(int r, int c)
{
	int r1, c1, i;

	if(suc){
		return;
	}
	if(cc == 0){
		suc = true;
		return;
	}
	for(i = 0; i < 4; ++i){
		r1 = r + d[i][0];
		c1 = c + d[i][1];
		if(
			r1 >= 0 && r1 <= n - 1 &&
			c1 >= 0 && c1 <= m - 1 &&
			!b[r1][c1] && s[r1][c1] == '.'
		){
			b[r1][c1] = 1;
			--cc;
			dfs(r1, c1);
			b[r1][c1] = 0;
			++cc;
		}
		if(suc){
			return;
		}
	}
}

int main()
{
	int i, j;
	int ns;

	while(scanf("%d%d", &n, &m) == 2 && (n || m)){
		memset(s, 0, MAXN * MAXN * sizeof(char));
		memset(b, 0, MAXN * MAXN * sizeof(int));
		for(i = 0; i < n; ++i){
			scanf("%s", s[i]);
		}
		ns = 0;
		for(i = 0; i < n; ++i){
			for(j = 0; j < m; ++j){
				if(s[i][j] == '.'){
					++ns;
				}
			}
		}
		suc = false;
		for(i = 0; i < n; ++i){
			for(j = 0; j < m; ++j){
				if(s[i][j] == '.'){
					cc = ns;
					b[i][j] = 1;
					--cc;
					dfs(i, j);
					b[i][j] = 0;
					++cc;
					break;
				}
			}
		}

		if(suc){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}

	return 0;
}

