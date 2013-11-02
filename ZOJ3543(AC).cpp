#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef long long int LL;
LL f[1005][1005];
LL sum[1005][1005];
LL total;
const LL mod = 	1000000007;

int main()
{
	int i, j;
	char s[2000];
	int slen;
	
	while(true){
		if(gets(s) == NULL){
			break;
		}
		slen = strlen(s);
		memset(f, 0, 1005 * 1005 * sizeof(LL));
		memset(sum, 0, 1005 * 1005 * sizeof(LL));
		f[0][0] = 1;
		for(i = 0; i < slen; ++i){
			sum[0][i + 1] = 1;
		}
		
		for(i = 1; i <= slen; ++i){
			for(j = 1; j <= i + 1; ++j){
				if(s[i - 1] == 'I' || s[i - 1] == '?'){
					f[i][j] += sum[i - 1][j - 1];
					while(f[i][j] >= mod){
						f[i][j] -= mod;
					}
					while(f[i][j] < 0){
						f[i][j] += mod;
					}
				}
				if(s[i - 1] == 'D' || s[i - 1] == '?'){
					f[i][j] += (sum[i - 1][i] - sum[i - 1][j - 1]);
					while(f[i][j] >= mod){
						f[i][j] -= mod;
					}
					while(f[i][j] < 0){
						f[i][j] += mod;
					}
				}
				sum[i][j] = f[i][j] + sum[i][j - 1];
				while(sum[i][j] >= mod){
					sum[i][j] -= mod;
				}
				while(sum[i][j] < 0){
					sum[i][j] += mod;
				}
			}
		}
		
		total = 0;
		for(i = 0; i <= slen + 1; ++i){
			total += f[slen][i];
			if(total >= mod){
				total -= mod;
			}
		}
		
		printf("%lld\n", total);
	}
	
	return 0;
}

