#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	int d;
	int q, r;
	double mincost;
	
	while(true){
		if(scanf("%d", &d) != 1){
			break;
		}else if(0 == d){
			break;
		}
		
		if(d > 0 && d <= 4){
			mincost = 10;
			printf("%d\n", (int)mincost);
		}else if(d > 4 && d <= 8){
			mincost = 10 + 2 * (d - 4);
			printf("%d\n", (int)mincost);
		}else{
			q = d / 8;
			r = d % 8;
			if(0 == r){
				mincost = 18 * q;
				printf("%d\n", (int)mincost);
			}else if(r > 0 && r <= 4){
				mincost = 18 * q + r * 2.4;
				printf("%.1f\n", mincost);
			}else{
				mincost = 18 * q + 10 + (r - 4) * 2;
				printf("%d\n", (int)mincost);
			}
		}
	}
	
	return 0;
}

