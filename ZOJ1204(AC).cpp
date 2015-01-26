#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <map>
using namespace std;

int a[100];
int n, m;
int r[100];
bool suc;
int totsum;
map<int, int> mm;

//example for bad case:
//1
//30 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 3000000000
void dfs(int cn, int ci, int sum, int len)
{
	int i;

	if(cn == len){
		if(mm.find(sum) != mm.end()){
			for(i = 0; i < len; ++i){
				if(i == len - 1){
					printf("%d=", r[i]);
				}else{
					printf("%d+", r[i]);
				}
			}
			printf("%d\n", sum);
			suc = true;

			return;
		}else{
			return;
		}
	}
	
	if(sum > a[m - 1]){
		//sum too large
		return;
	}

	if(len - cn > (m - 1) - (ci)){
		//number not enough
		return;
	}

	for(i = ci; i < m - 1; ++i){
		r[cn] = a[i];
		dfs(cn + 1, i + 1, sum + a[i], len);
	}
}

int main()
{
	int ni, i;
	
	while(true){
		if(scanf("%d", &n) != 1){
			break;
		}
		for(ni = 0; ni < n; ++ni){
			scanf("%d", &m);
			totsum = 0;
			mm.clear();
			for(i = 0; i < m; ++i){
				scanf("%d", &a[i]);
				totsum += a[i];
				mm.insert(pair<int, int>(a[i], 0));
			}
			sort(a, a + m);
			suc = false;
			for(i = 2; i <= m - 1; ++i){
				dfs(0, 0, 0, i);
			}

			if(!suc){
				printf("Can't find any equations.\n");
			}
			printf("\n");
		}
	}
	
	return 0;
}
