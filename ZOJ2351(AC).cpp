#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	int t, ti;
	double ka, s;
	double x;
	int m, n;
	double d;

	while(scanf("%d", &t) == 1){
		for(ti = 0; ti < t; ++ti){
			if(ti > 0){
				printf("\n");
			}
			while(scanf("%lf%lf%d%d", &ka, &s, &m, &n) == 4 && (ka || s || m || n)){
				d = ka / (m * n * s);
				x = 0.5 * (sqrt(d * (d + 4)) - d);
				printf("%.3f\n", -(log(m * s * x) / log(10.0)));
			}
		}
	}

	return 0;
}

