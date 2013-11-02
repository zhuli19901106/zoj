#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	int i;
	int n;
	int c[102];
	int dc[101];
	int t;

	scanf("%d", &t);
	while(t--){
		for(i = 0; i < 102; i++){
			c[i] = 0;
		}

		for(i = 0; i < 101; i++){
			dc[i] = 0;
		}

		scanf("%d", &n);
		for(i = n; i >= 0; i--){
			scanf("%d", &c[i]);
		}

		for(i = n; i > 0; i--){
			dc[i - 1] = c[i] * i;
		}
		if(n > 0){
			n--;
		}

		for(i = n; i >= 0; i--){
			printf("%d", dc[i]);
			if(i > 0){
				printf(" ");
			}
		}
		printf("\n");
	}

	return 0;
}

