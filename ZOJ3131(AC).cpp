#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int a[86400];

int main()
{
	int h, m, s;
	int i;
	int t, ti;
	int n1, n2;

	memset(a, 0, 86400 * sizeof(int));
	a[0] = 1;
	for(i = 1; i < 86400; ++i){
		h = i / 3600;
		m = i % 3600 / 60;
		s = i % 60;
		if((h + m + s) % 3 == 0){
			a[i] = a[i - 1] + 1;
		}else{
			a[i] = a[i - 1];
		}
	}

	while(scanf("%d", &t) == 1){
		for(ti = 0; ti < t; ++ti){
			scanf("%2d%*1s%2d%*1s%2d", &h, &m, &s);
			n1 = h * 3600 + m * 60 + s;
			scanf("%2d%*1s%2d%*1s%2d", &h, &m, &s);
			n2 = h * 3600 + m * 60 + s;

			if(n1 <= n2){
				if(n1 == 0){
					printf("%d\n", a[n2]);
				}else{
					printf("%d\n", a[n2] - a[n1 - 1]);
				}
			}else{
				printf("%d\n", a[n2] + a[86399] - a[n1 - 1]);
			}
		}
	}

	return 0;
}

