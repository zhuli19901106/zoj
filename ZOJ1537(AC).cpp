#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	int i;
	int j;
	int x;
	int n;
	int k;
	int success;
	
	while(true){
		if(scanf("%d", &k) == 1){
			x = 1;
			n = 1;

			success = 0;
			for(i = 1; success == 0 && i <= 9; i++){
				x = 0;
				for(j = 1; success == 0 && j <= k; j++){
					x = (x * 10 + i) % k;
					if(x == 0){
						success = 1;
						printf("%d %d\n", i, j);
						break;
					}
				}
			}
			
			if(success == 0){
				printf("-1\n");
			}
		}else{
			break;
		}
	}
		
	return 0;
}

