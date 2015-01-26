#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXN = 20;
const int INF = 999999999;
class Matrix{
public:
	int w;
	int h;
	int left;
	int right;
	int value;

	Matrix(const int _w = 0, const int _h = 0)
	{
		w = _w;
		h = _h;
		left = -1;
		right = -1;
		value = 0;
	}
};

Matrix a[MAXN][MAXN];
int n;

void print_recursive(int left, int right)
{
	if(left < 1 || left > n || right < 1 || right > n){
		return;
	}

	if(left > right){
		return;
	}

	if(left == right){
		printf("A%d", left);
	}else{
		printf("(");
		print_recursive(left, a[left][right].left);
		printf(" x ");
		print_recursive(a[left][right].right, right);
		printf(")");
	}
}

int main()
{
	int i, j, k;
	int ti;
	int value;

	ti = 0;
	while(scanf("%d", &n) == 1 && n){
		++ti;
		memset(a, 0, MAXN * MAXN * sizeof(Matrix));

		for(i = 1; i <= n; ++i){
			scanf("%d%d", &a[i][i].w, &a[i][i].h);
		}
		if(n == 1){
			printf("Case %d: A1\n", ti);
			continue;
		}

		for(i = 1; i <= n; ++i){
			for(j = i + 1; j <= n; ++j){
				a[i][j].w = a[i][i].w;
				a[i][j].h = a[j][j].h;
				a[i][j].left = -1;
				a[i][j].right = -1;
				a[i][j].value = INF;
			}
		}

		for(i = 1; i <= n; ++i){
			a[i][i].value = 0;
			a[i][i].left = -1;
			a[i][i].right = -1;
		}
		for(i = 1; i < n; ++i){
			a[i][i + 1].value = a[i][i].w * a[i][i].h * a[i + 1][i + 1].h;
			a[i][i + 1].left = i;
			a[i][i + 1].right = i + 1;
		}
		for(i = 2; i < n; ++i){
			for(j = 1; j + i <= n; ++j){
				for(k = j; k + 1 <= j + i; ++k){
					value = a[j][k].value + a[k + 1][j + i].value + a[j][k].w * a[j][k].h * a[k + 1][j + i].h;
					if(value < a[j][j + i].value){
						a[j][j + i].value = value;
						a[j][j + i].left = k;
						a[j][j + i].right = k + 1;
					}
				}
			}
		}

		printf("Case %d: ", ti);
		print_recursive(1, n);
		printf("\n");
	}
	
	return 0;
}
