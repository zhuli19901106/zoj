#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

int n;
int a[20];
double r[6][6];
double m;

double round_2(const double &d)
{
	return floor(d * 100.0 + 0.5) / 100.0;
}

int main()
{
	int i, j;
	int t, ti;

	while(scanf("%d", &t) == 1){
		for(ti = 0; ti < t; ++ti){
			if(ti > 0){
				printf("\n");
			}

			for(i = 1; i <= 5; ++i){
				for(j = 1; j <= 5; ++j){
					scanf("%lf", &r[i][j]);
				}
			}
			while(scanf("%d", &n) == 1 && n){
				for(i = 0; i < n; ++i){
					scanf("%d", &a[i]);
				}
				scanf("%lf", &m);
				
				m = round_2(m * r[1][a[0]]);
				for(i = 1; i < n; ++i){
					m = round_2(m * r[a[i - 1]][a[i]]);
				}
				m = round_2(m * r[a[n - 1]][1]);
				printf("%.2f\n", m);
			}
		}
	}

	return 0;
}
