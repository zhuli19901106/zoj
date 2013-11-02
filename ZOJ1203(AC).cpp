#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

double p[100][2];
typedef struct st{
	int a;
	int b;
	double d;
}st;
vector<st> vv;
int n;
int a[100];
double res;

bool comparator(const st &a, const st &b)
{
	return a.d < b.d;
}

double dist(const double a[], const double b[])
{
	return sqrt((a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]));
}

int find_root(int x)
{
	int r, k;

	r = x;
	while(r != a[r]){
		r = a[r];
	}

	k = x;
	while(x != r){
		x = a[x];
		a[k] = r;
		k = x;
	}

	return r;
}

int main()
{
	int i, j, cc;
	st edge;
	int ra, rb;
	int ti;

	ti = 0;
	while(scanf("%d", &n) == 1 && n){
		++ti;
		memset(p, 0, 100 * 2 * sizeof(double));
		for(i = 0; i < n; ++i){
			scanf("%lf%lf", &p[i][0], &p[i][1]);
		}

		vv.clear();
		for(i = 0; i < n - 1; ++i){
			for(j = i + 1; j < n; ++j){
				edge.a = i;
				edge.b = j;
				edge.d = dist(p[i], p[j]);
				vv.push_back(edge);
			}
		}

		memset(a, 0, 100 * sizeof(int));
		for(i = 0; i < n; ++i){
			a[i] = i;
		}

		res = 0.0;
		cc = 0;
		sort(vv.begin(), vv.end(), comparator);
		for(i = 0; i < (int)vv.size(); ++i){
			if(cc >= n - 1){
				break;
			}
			ra = find_root(vv[i].a);
			rb = find_root(vv[i].b);
			if(ra != rb){
				a[ra] = rb;
				res += vv[i].d;
				++cc;
				find_root(vv[i].a);
				find_root(vv[i].b);
			}
		}

		if(ti > 1){
			printf("\n");
		}
		printf("Case #%d:\n", ti);
		printf("The minimal distance is: %.2f\n", res);
	}

	return 0;
}

