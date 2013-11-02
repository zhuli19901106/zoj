#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

vector<int> v[10005];
int a[10005];
int b[10005];
int p[2500];
int pc;

int main()
{
	int i, j, n;

	memset(b, 0, 10005 * sizeof(int));
	b[0] = b[1] = 1;
	for(i = 2; i * i <= 10000; ++i){
		if(b[i]){
			continue;
		}
		for(j = i; i * j <= 10000; ++j){
			b[i * j] = 1;
		}
	}

	pc = 0;
	for(i = 0; i <= 10000; ++i){
		b[i] = !b[i];
		if(b[i]){
			p[pc++] = i;
		}
	}

	memset(a, 0, 10005 * sizeof(int));
	for(i = 0; i < pc; ++i){
		a[p[i]] = 1;
		v[p[i]].push_back(p[i]);
	}

	for(i = 0; i < pc; ++i){
		for(j = i; j >= 0; --j){
			if(p[i] + p[j] <= 10000 && a[p[i] + p[j]] == 0){
				a[p[i] + p[j]] = 2;
				v[p[i] + p[j]].push_back(p[i]);
				v[p[i] + p[j]].push_back(p[j]);
			}
		}
	}
	
	for(i = 4; i <= 10000; ++i){
		if(a[i] == 0){
			for(j = 0; j < pc; ++j){
				if(i <= p[j]){
					continue;
				}
				if(a[i - p[j]] == 2){
					if(p[j] < v[i - p[j]][0]){
						continue;
					}
					a[i] = 3;
					v[i].push_back(p[j]);
					v[i].push_back(v[i - p[j]][0]);
					v[i].push_back(v[i - p[j]][1]);
					break;
				}
			}
		}
	}

	/*
	for(i = 0; i <= 10000; ++i){
		printf("%d = ", i);
		for(j = 0; j < v[i].size(); ++j){
			if(j > 0){
				printf(" + %d", v[i][j]);
			}else{
				printf("%d", v[i][j]);
			}
		}
		printf("\n");
	}
	*/

	while(scanf("%d", &n) == 1){
		printf("%d\n", (int)v[n].size());
		if(v[n].size() == 0){
			continue;
		}
		for(i = 0; i < (int)v[n].size(); ++i){
			if(i > 0){
				printf(" %d", v[n][i]);
			}else{
				printf("%d", v[n][i]);
			}
		}
		printf("\n");
	}
	
	return 0;
}

