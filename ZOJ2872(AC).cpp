#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

const int mod = 1000000;

int main()
{
	int *f;
	int n, i;
	int case_no, case_count;
	
	f = NULL;
	f = (int *)malloc(2000000 * sizeof(int));
	f[0] = 1;
	f[1] = 1;
	for(i = 2; i <= 2000000; ++i){
		if(i % 2){
			f[i] = f[i - 1];
		}else{
			f[i] = f[i - 1] + f[i / 2];
			while(f[i] >= mod){
				f[i] -= mod;
			}
		}
	}
	
	while(true){
		if(scanf("%d", &case_count) != 1){
			break;
		}
		
		for(case_no = 0; case_no < case_count; ++case_no){
			scanf("%d", &n);
			printf("%d\n", f[n]);
		}
	}
	
	return 0;
}
