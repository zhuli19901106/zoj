#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <queue>
using namespace std;

int main()
{
	int n;
	int m;
	int i;
	int j;
	int degree[20];
	int x;
	int y;
	int a[20][20];
	int error;
	int qc[20];
	int tmp;
	int case_count;
	queue<int> q;

	case_count = 0;
	while(true){
		error = 0;
		for(i = 0; i < 20; i++){
			degree[i] = 0;
			for(j = 0; j < 20; j++){
				a[i][j] = 0;
			}
		}

		if(scanf("%d%d", &n, &m) != 2){
			break;
		}else{
			case_count++;
		}
		for(i = 0; i < m; i++){
			scanf("%d%d", &x, &y);
			degree[x]++;
			degree[y]++;
			a[x][y] = a[y][x] = 1;
		}

		if(m != n){
			printf("NO\n");
			error = 1;
			continue;
		}else{
			for(i = 1; i <= n; i++){
				if(degree[i] != 2){
					error = 1;
					break;
				}
			}
			if(error == 1){
				printf("NO\n");
				continue;
			}

			for(i = 0; i < 20; i++){
				qc[i] = 0;
			}
			q.push(1);
			while(q.size() > 0){
				tmp = q.front();
				q.pop();
				qc[tmp] = 1;
				for(i = 1; i <= n; i++){
					if(a[tmp][i] == 1 &&qc[i] == 0){
						q.push(i);
					}
				}
			}

			for(i = 1; i <= n; i++){
				if(qc[i] != 1){
					error = 1;
				}
			}
			if(error == 1){
				printf("NO\n");
				continue;
			}

			printf("YES\n");
		}
	}

	return 0;
}

