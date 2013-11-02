#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

int a[1000][1000];
bool v[1000];
int qsw[1000];
int vc;
int n;
int tot;

int main()
{
	int case_count;
	int case_no;
	int i, j;
	int min_w, min_j;
	
	while(true){
		if(scanf("%d", &case_count) != 1){
			break;
		}
		for(case_no = 0; case_no < case_count; ++case_no){
			scanf("%d", &n);
			for(i = 0; i < n; ++i){
				scanf("%d", &qsw[i]);
			}
			for(i = 0; i < n; ++i){
				for(j = 0; j < n; ++j){
					scanf("%d", &a[i][j]);
				}
			}

			for(i = 0; i < n; ++i){
				for(j = 0; j < n; ++j){
					if(i == j){
						continue;
					}else{
						a[i][j] += (qsw[i] + qsw[j]);
					}
				}
			}

			for(i = 0; i < n; ++i){
				v[i] = false;
			}

			vc = 1;
			v[0] = true;
			tot = 0;
			while(vc < n){
				min_w = 10000000;
				min_j = -1;
				for(i = 0; i < n; ++i){
					if(v[i] == false){
						continue;
					}
					for(j = 0; j < n; ++j){
						if(v[j] == true){
							continue;
						}
						if(i == j){
							continue;
						}
						if(a[i][j] < min_w){
							min_w = a[i][j];
							min_j = j;
						}
					}
				}
				v[min_j] = true;
				tot += min_w;
				++vc;
			}

			printf("%d\n", tot);
		}
	}
	
	return 0;
}

