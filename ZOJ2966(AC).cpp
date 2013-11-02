#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

typedef struct st{
	int a;
	int b;
	int len;
}st;

bool st_comparator(const st &x, const st &y)
{
	return x.len < y.len;
}

const int MAXN = 505;
vector<st> ve;
int dj[MAXN];
int n, e, cc, res;

int find_root(int x)
{
	int k, r;

	r = x;
	while(r != dj[r]){
		r = dj[r];
	}

	k = x;
	while(x != r){
		x = dj[x];
		dj[k] = r;
		k = x;
	}

	return r;
}

int main()
{
	st tmp;
	int i;
	int ra, rb;
	int t, ti;

	while(scanf("%d", &t) == 1){
		for(ti = 0; ti < t; ++ti){
			scanf("%d%d", &n, &e);
			for(i = 0; i < n; ++i){
				dj[i] = i;
			}

			ve.clear();
			for(i = 0; i < e; ++i){
				scanf("%d%d%d", &tmp.a, &tmp.b, &tmp.len);
				ve.push_back(tmp);
			}

			cc = n - 1;
			res = 0;
			sort(ve.begin(), ve.end(), st_comparator);
			for(i = 0; i < (int)ve.size(); ++i){
				if(cc <= 0){
					break;
				}else{
					ra = find_root(ve[i].a);
					rb = find_root(ve[i].b);
					if(ra != rb){
						dj[ra] = rb;
						find_root(ve[i].a);
						find_root(ve[i].b);
						res += ve[i].len;
						--cc;
					}
				}
			}

			printf("%d\n", res);
		}
	}

	return 0;
}

