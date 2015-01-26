#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <map>
using namespace std;

int a[500005];
map<int, int> mp;
int n, m;

int main()
{
	int i, j;
	int x, y;

	while(true){
		if(scanf("%d", &n) != 1){
			break;
		}
		
		for(i = 1; i <= n; ++i){
			scanf("%d", &a[i]);
		}
		scanf("%d", &m);
		for(i = 1; i <= m; ++i){
			scanf("%d%d", &x, &y);
			mp.clear();
			for(j = y; j >= x; --j){
				if(mp.find(a[j]) != mp.end()){
					printf("%d\n", a[j]);
					break;
				}else{
					mp.insert(pair<int, int>(a[j], 0));
				}
			}
			if(j == x - 1){
				printf("OK\n");
			}
		}
		printf("\n");
	}
	
	return 0;
}
