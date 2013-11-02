#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXN = 1000001;
const int MAXP = 80000;
int f[MAXN];
int b[MAXN];
int d[MAXN];
int p[MAXP];
int pc;

int main()
{
	int i, j, n;

	memset(b, 0, MAXN * sizeof(int));
	memset(p, 0, MAXP * sizeof(int));
	b[0] = b[1] = 1;
	pc = 0;
	for(i = 2; i < MAXN; ++i){
		if(!b[i]){
			p[pc++] = i;
			f[i] = 1;
			d[i] = 2;
		}

		for(j = 0; j < pc && i * p[j] < MAXN; ++j){
			b[i * p[j]] = 1;
			if(i % p[j]){
				d[i * p[j]] = d[i] * d[p[j]];
				f[i * p[j]] = 1;
			}else{
				d[i * p[j]] = d[i] / (f[i] + 1) * (f[i] + 2);
				f[i * p[j]] = f[i] + 1;
				break;
				//break here to avoid duplicate counting.
			}
		}
	}
	d[1] = 1;

	memset(f, 0, MAXN * sizeof(int));
	for(i = 1; i < MAXN; ++i){
		n = d[i];
		d[i] = f[n];
		++f[n];
	}

	while(scanf("%d", &n) == 1){
		printf("%d\n", d[n]);
	}

	return 0;
}

