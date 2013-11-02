#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

int p[1100];
int t[1100];
int dt[1100];
int sdt[1100];
double w;
double mw;
double ave;
double mave;
int tot;
int wc;
int n;

int comp(const void *a, const void *b)
{
	return *(const int *)a - *(const int *)b;
}

int main()
{
	int i;
	int j;
	int case_count;
	int case_no;
	
	while(true){
		if(scanf("%df", &case_count) != 1){
			break;
		}
		
		for(case_no = 0; case_no < case_count; ++case_no){
			scanf("%d", &n);
			for(i = 0; i < n; ++i){
				scanf("%d", &p[i]);
			}
			for(i = 0; i < n; ++i){
				scanf("%d", &t[i]);
			}
			dt[0] = t[0];
			sdt[0] = t[0];
			for(i = 1; i < n; ++i){
				dt[i] = t[i] - t[i - 1];
				sdt[i] = t[i] - t[i - 1];
			}
			qsort(sdt, n, sizeof(int), comp);

			w = -1;
			mw = -1;
			mave = -1;
			i = 0;
			while(true){
				if(i >= n){
					break;
				}else if(w >= sdt[i]){
					++i;
				}else{
					w = sdt[i];
					wc = 0;
					tot = 0;
					for(j = 0; j < n; ++j){
						if(dt[j] > w){
							//fallen asleep
							break;
						}else{
							++wc;
							tot = tot + p[j];
						}
					}
					
					if(wc > 0){
						ave = 1.0 * tot / wc;
					}else{
						ave = 0;
					}
					
					if(ave > mave){
						mave = ave;
						mw = w;
					}
				}
			}
			
			printf("%.6f %.6f\n", mw, mave);
		}
	}
	
	return 0;
}

