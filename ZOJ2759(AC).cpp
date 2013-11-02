#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef long long int LL;

LL max_sum;
LL base3;
const LL MAXM = 500000000;
LL m;
LL sum;
int w[100];
LL r[100];
int rc;
LL left[100], cl;
LL right[100], cr;

int main()
{
	int i = 0;
	
	max_sum = 0;
	base3 = 1;
	rc = 0;
	while(true){
		if(max_sum >= MAXM){
			break;
		}else{
			max_sum += base3;
			r[rc] = base3;
			base3 *= 3;
			++rc;
		}
	}

	while(true){
		if(scanf("%lld", &m) != 1){
			break;
		}
		m = m + max_sum;
		for(i = rc - 1; i >= 0; --i){
			w[i] = 1;
		}

		for(i = rc - 1; i >= 0; --i){
			w[i] = (int)(m / r[i]);
			m %= r[i];
		}

		for(i = rc - 1; i >= 0; --i){
			--w[i];
		}
		
		cl = 0;
		cr = 0;
		for(i = 0; i < rc; ++i){
			if(w[i] == -1){
				left[cl++] = r[i];
			}else if(w[i] == +1){
				right[cr++] = r[i];
			}
		}
		
		if(cl == 0){
			printf("-1\n");
		}else{
			for(i = 0; i < cl; ++i){
				if(i > 0){
					printf(" %lld", left[i]);
				}else{
					printf("%lld", left[i]);
				}
			}
			printf("\n");
		}

		if(cr == 0){
			printf("-1\n");
		}else{
			for(i = 0; i < cr; ++i){
				if(i > 0){
					printf(" %lld", right[i]);
				}else{
					printf("%lld", right[i]);
				}
			}
			printf("\n");
		}
		printf("\n");
	}
	
	return 0;
}

