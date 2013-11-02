#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

//Watch out for the kengdie data range, "int" will not suffice...
long long int dp[505][505];

int main()
{
	int i, j;
	int n;
	
	for(i = 0; i <= 500; ++i){
		for(j = 0; j <= 500; ++j){
			if(i == 0){
				dp[i][j] = 1;
				continue;
			}
			
			if(j == 0){
				dp[i][j] = 0;
				continue;
			}

			if(i >= j){
				dp[i][j] = dp[i][j - 1] + dp[i - j][j - 1];
			}else{
				dp[i][j] = dp[i][j - 1];
			}
		}
	}

	while(true){
		if(scanf("%d", &n) != 1){
			break;
		}else if(n <= 0){
			break;
		}else{
			printf("%lld\n", dp[n][n] - 1);
		}
	}
	
	return 0;
}

