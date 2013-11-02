#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
	int an;
	int i, j, n;
	int bit[120000];
	int bc;
	int sum, tmp;
	
	while(true){
		if(scanf("%d", &n) != 1){
			break;
		}else if(-1 == n){
			break;
		}

		memset(bit, 0, 120000 * sizeof(int));
		bc = 0;
		for(i = 0; i < n; ++i){
			scanf("%d", &an);
			for(j = 15; j >= 0; --j){
				bit[bc + j] = an % 2;
				an = an / 2;
			}
			bc = bc + 16;
		}
		
		sum = 0;
		for(i = 0; i < bc; i = i + 7){
			tmp = 0;
			for(j = 1; j <= 6; ++j){
				tmp = tmp * 2 + bit[i + j];
			}
			if(bit[i]){
				tmp = -tmp;
			}
			sum = sum + tmp;
		}
		
		printf("%d\n", sum);
	}
	
	return 0;
}

