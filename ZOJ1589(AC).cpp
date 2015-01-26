#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

/*
	3155595	2012-12-19 19:04:07	 Accepted	1589	C++	0	180	3090101804
	Simple application of Floyd's Algorithm to calculate the transitive enclosure of a directed graph.
*/

int main()
{
	int a[26][26];
	int n, m;
	int ni;
	int cc;
	int i, j, k;
	char s[1000];
	
	while(true){
		if(scanf("%d", &n) != 1){
			break;
		}
		for(ni = 1; ni <= n; ++ni){
			scanf("%d", &m);
			memset(a, 0, 26 * 26 * sizeof(int));
			for(i = 0; i < m; ++i){
				scanf("%s", s);
				if(s[1] == '<'){
					if(s[0] >= 'A' && s[0] <= 'Z' && s[2] >= 'A' && s[2] <= 'Z'){
						a[s[0] - 'A'][s[2] - 'A'] = 1;
					}
				}else if(s[1] == '>'){
					if(s[0] >= 'A' && s[0] <= 'Z' && s[2] >= 'A' && s[2] <= 'Z'){
						a[s[2] - 'A'][s[0] - 'A'] = 1;
					}
				}
			}
			
			for(k = 0; k < 26; ++k){
				for(i = 0; i < 26; ++i){
					if(k == i){
						continue;
					}
					for(j = 0; j < 26; ++j){
						if(j == i || j == k){
							continue;
						}
						if(a[i][k] > 0 && a[k][j] > 0){
							if(a[i][j] == 0 || a[i][j] > a[i][k] + a[k][j]){
								a[i][j] = a[i][k] + a[k][j];
							}
						}
					}
				}
			}
			
			printf("Case %d:\n", ni);
			cc = 0;
			for(i = 0; i < 26; ++i){
				for(j = 0; j < 26; ++j){
					if(i == j){
						continue;
					}
					if(a[i][j] > 1){
						printf("%c<%c\n", i + 'A', j + 'A');
						++cc;
					}
				}
			}
			
			if(0 == cc){
				printf("NONE\n");
			}
		}
	}
	
	return 0;
}
