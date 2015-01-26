#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int a, b, c;
int min_res;
int max_res;

int main()
{
	int t, ti;
	int i;
	int comb;

	while(scanf("%d", &t) == 1){
		for(ti = 0; ti < t; ++ti){
			scanf("%d%d%d", &a, &b, &c);
			comb = 0;
			min_res = 0;
			for(i = 1; i <= a; ++i){
				min_res += 300 * (comb * 2 + 1);
				++comb;
			}
			for(i = 1; i <= b; ++i){
				min_res += 100 * (comb * 2 + 1);
				++comb;
			}
			for(i = 1; i <= c; ++i){
				min_res += 50 * (comb * 2 + 1);
				++comb;
			}

			comb = 0;
			max_res = 0;
			for(i = 1; i <= c; ++i){
				max_res += 50 * (comb * 2 + 1);
				++comb;
			}
			for(i = 1; i <= b; ++i){
				max_res += 100 * (comb * 2 + 1);
				++comb;
			}
			for(i = 1; i <= a; ++i){
				max_res += 300 * (comb * 2 + 1);
				++comb;
			}

			printf("%d %d\n", min_res, max_res);
		}
	}

	return 0;
}
