
#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

typedef long long int LL;
const int MAXN = 50000;
int b[MAXN], n;
int p[20000];
int pc;
map<int, LL> mm;
map<vector<int>, LL> mv;

LL mysolve(int n)
{
	int rt, i;
	int x, c;
	LL res, tmp;
	vector<int> vv;

	if(mm[n]){
		return mm[n];
	}

	x = n;
	i = 0;
	vv.clear();
	while(i < pc && p[i] <= x / p[i]){
		if(x % p[i] == 0){
			c = 0;
			while(x % p[i] == 0){
				++c;
				x /= p[i];
			}
			vv.push_back(c);
		}
		++i;
	}
	if(x > 1){
		vv.push_back(1);
	}
	sort(vv.begin(), vv.end());
	if(mv.find(vv) != mv.end()){
		return mv[vv];
	}

	rt = (int)sqrt(1.0 * n);
	res = 0;
	for(i = 2; i <= rt; ++i){
		if(n % i == 0){
			if(i < n / i){
				res += 2 * mysolve(i) * mysolve(n / i);
			}else{
				tmp = mysolve(i);
				res += tmp * tmp;
			}
		}
	}

	if(!res){
		res = 1;
	}
	mm[n] = res;
	mv[vv] = res;

	return res;
}

int main()
{
	int i, j;

	memset(b, 0, MAXN * sizeof(int));
	b[0] = b[1] = 1;
	for(i = 2; i <= (MAXN - 1) / i; ++i){
		if(b[i]){
			continue;
		}
		for(j = i; j <= (MAXN - 1) / i; ++j){
			b[i * j] = 1;
		}
	}
	
	pc = 0;
	for(i = 0; i < MAXN; ++i){
		b[i] = !b[i];
		if(b[i]){
			p[pc++] = i;
		}
	}

	mm.clear();
	while(scanf("%d", &n) == 1){
		printf("%lld\n", mysolve(n));
	}

	return 0;
}
