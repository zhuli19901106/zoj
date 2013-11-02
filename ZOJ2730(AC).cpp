#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

bool success;
int edge[50][50];
int ec;
int path[5000];
int n;

void dfs(int current_node)
{
	int i;

	if(success){
		return;
	}
	
	if(ec == n * (n - 1) / 2 && path[ec] == 0){
		success = true;
		printf("%d\n", ec);
		for(i = 0; i < ec; ++i){
			printf((i > 0 ? " %d" : "%d"), path[i]);
		}
		printf("\n");
		
		return;
	}
	
	for(i = 0; i < n; ++i){
		if(i == current_node){
			continue;
		}else if(!edge[current_node][i]){
			edge[current_node][i] = edge[i][current_node] = 1;
			path[ec + 1] = i;
			++ec;
			dfs(i);
			edge[current_node][i] = edge[i][current_node] = 0;
			--ec;
		}
	}
}

int main()
{
	while(true){
		if(scanf("%d", &n) != 1){
			break;
		}
		
		success = false;
		memset(edge, 0, 50 * 50 * sizeof(int));
		memset(path, 0, 5000 * sizeof(int));
		ec = 0;
		path[ec] = 0;
		dfs(0);
	}

	return 0;
}

