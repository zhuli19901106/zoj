#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int n, m;
int c[10];
int v[10];
int cc[10];
int total_count;

//One more parameter is needed for this DFS, the index
void dfs(int sum, int index)
{
	int i;
	
	if(sum == n){
		++total_count;
		return;
	}
	
	for(i = index; i < m; ++i){
		if(cc[i] < c[i] && sum + v[i] <= n){
			++cc[i];
			dfs(sum + v[i], i);
			--cc[i];
		}
	}
}

int main()
{
	int i;
	int test_case;
	
	test_case = 0;
	while(true){
		if(scanf("%d%d", &n, &m) != 2){
			break;
		}
		
		for(i = 0; i < m; ++i){
			scanf("%d%d", &v[i], &c[i]);
		}
		
		total_count = 0;
		memset(cc, 0, 10 * sizeof(int));
		dfs(0, 0);
		
		++test_case;
		if(test_case > 1){
			printf("\n");
		}
		printf("%d\n", total_count);
	}
	
	return 0;
}

