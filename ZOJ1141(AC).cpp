#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXN = 2001;
int h[MAXN];
int dj[MAXN];
int c[MAXN];
int n;
int nq;

int lca(int x, int y)
{
	int i;
	int df;

	if(h[x] < h[y]){
		df = h[y] - h[x];
		for(i = 0; i < df; ++i){
			y = dj[y];
		}
	}else if(h[x] > h[y]){
		df = h[x] - h[y];
		for(i = 0; i < df; ++i){
			x = dj[x];
		}
	}
	//Now both nodes are at same level
	while(x != y){
		x = dj[x];
		y = dj[y];
	}

	return x;
}

int main()
{
	int i, j;
	int count;
	int x, y;
	int p[MAXN];
	int pc;
	char s1[10], s2[10], s3[10];

	while(true){
		if(scanf("%d", &n) != 1){
			break;
		}
		memset(h, 0, MAXN * sizeof(int));
		memset(c, 0, MAXN * sizeof(int));
		memset(dj, 0, MAXN * sizeof(int));
		for(i = 1; i <= n; ++i){
			dj[i] = i;
		}
		for(i = 1; i <= n; ++i){
			scanf("%d%1s%1s%d%1s", &x, s1, s2, &count, s3);
			for(j = 1; j <= count; ++j){
				scanf("%d", &y);
				dj[y] = x;
			}
		}

		//Calculate the depth of the nodes
		for(i = 1; i <= n; ++i){
			if(h[i] > 0){
				continue;
			}
			pc = 0;
			x = i;
			while(h[x] == 0){
				p[pc++] = x;
				if(dj[x] == x){
					break;
				}else{
					x = dj[x];
				}
			}
			if(h[x] > 0){
				h[p[pc - 1]] = h[x] + 1;
				for(j = pc - 2; j >= 0; --j){
					h[p[j]] = h[p[j + 1]] + 1;
				}
			}else{
				h[p[pc - 1]] = 1;
				for(j = pc - 2; j >= 0; --j){
					h[p[j]] = h[p[j + 1]] + 1;
				}
			}
		}

		scanf("%d", &nq);
		for(i = 1; i <= nq; ++i){
			scanf("%1s%d%1s%d%1s", s1, &x, s2, &y, s3);
			++c[lca(x, y)];
		}

		for(i = 1; i <= n; ++i){
			if(c[i] > 0){
				printf("%d:%d\n", i, c[i]);
			}
		}
	}

	return 0;
}
