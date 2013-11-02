#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int dj[100005];
int c[100005];
int n, m;

int find(int x)
{
	while(dj[x] != x){
		x = dj[x];
	}
	
	return x;
}

int find_compress(int x)
{
	if(dj[x] != x){
		dj[x] = find_compress(dj[x]);
		c[x] = c[dj[x]];
		
		return dj[x];
	}else{
		return x;
	}
}

int main()
{
	int i;
	char str[2000];
	int case_no;
	int x, y;
	int rx, ry;
	case_no = 0;
	while(true){
		if(scanf("%d%d", &n, &m) != 2){
			break;
		}else{
			++case_no;
		}
		
		if(case_no > 1){
			printf("\n");
		}
		printf("Case %d:\n", case_no);
		
		for(i = 1; i <= n; ++i){
			dj[i] = i;
			c[i] = 1;
		}
		
		for(i = 0; i < m; ++i){
			scanf("%s", str);
			if(strcmp(str, "M") == 0){
				scanf("%d%d", &x, &y);
				if(x == y){
					continue;
				}else{
					rx = find_compress(x);
					ry = find_compress(y);
					if(rx != ry){
						dj[rx] = ry;
						c[ry] = c[rx] + c[ry];
					}
				}
			}else if(strcmp(str, "Q") == 0){
				scanf("%d", &x);
				rx = find_compress(x);
				printf("%d\n", c[x]);
			}
		}
	}
	
	return 0;
}

