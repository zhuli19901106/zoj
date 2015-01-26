#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int dj[1001];

int find(int x)
{
	int r;
	
	r = x;
	while(dj[r] != r){
		r = dj[r];
	}
	
	return r;
}

int main()
{
	int n, m, i;
	int x, y;
	int rx, ry;
	bool suc;
	
	while(true){
		if(scanf("%d%d", &n, &m) != 2){
			break;
		}else if(0 == n && 0 == m){
			break;
		}
		
		for(i = 1; i <= n; ++i){
			dj[i] = i;
		}
		
		
		suc = true;
		for(i = 0; i < m; ++i){
			scanf("%d%d", &x, &y);
			if(!suc){
				continue;
			}
			rx = find(x);
			ry = find(y);
			if(rx == ry){
				suc = false;
			}else{
				dj[rx] = ry;
			}
		}

		m = 0;
		for(i = 1; i <= n; ++i){
			if(dj[i] == i){
				++m;
			}
		}
		if(m > 1){
			suc = false;
		}
		
		if(suc){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}
	
	return 0;
}
