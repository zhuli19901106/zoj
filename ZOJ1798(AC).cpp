#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int n;
int a[10][10];
int b[10];
bool suc;
int cc;

void dfs(int node)
{
	int i;

	if(suc){
		return;
	}

	if(cc == 0 && a[node][0]){
		suc = true;
	}

	for(i = 0; i <= n; ++i){
		if(i != node && !b[i] && a[node][i]){
			b[i] = 1;
			--cc;
			dfs(i);
			++cc;
			b[i] = 0;
		}
	}
}

int main()
{
	char s[100];
	int i, j;
	int ti;

	ti = 0;
	while(gets(s) != NULL){
		if(sscanf(s, "%d", &n) == 1 && n){
			++ti;
		}else{
			break;
		}
		memset(a, 0, 10 * 10 * sizeof(int));
		for(i = 1; i <= n; ++i){
			gets(s);
			for(j = 0; s[j]; ++j){
				if(s[j] >= '0' && s[j] <= '9'){
					a[i][s[j] - '0'] = a[s[j] - '0'][i] = 1;
				}
			}
		}

		suc = false;
		memset(b, 0, 10 * sizeof(int));
		cc = n + 1;

		b[0] = 1;
		--cc;
		dfs(0);
		++cc;
		b[0] = 0;

		if(suc){
			printf("Case %d: Granny can make the circuit.\n", ti);
		}else{
			printf("Case %d: Granny can not make the circuit.\n", ti);
		}
	}

	return 0;
}
