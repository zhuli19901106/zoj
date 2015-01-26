#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef long long int LL;
int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61};
int pc = 18;

int f[20];
int fc[20];
LL cc[20];
int fcc;
int digit[150];
LL s;
LL sum;
int k;

int main()
{
	int i;
	char str[1000];
	LL p;

	memset(digit, 0, 150 * sizeof(int));
	for(i = '0'; i <= '9'; ++i){
		digit[i] = i - '0';
	}
	for(i = 'A'; i <= 'Z'; ++i){
		digit[i] = i - 'A' + 10;
	}
	for(i = 'a'; i <= 'z'; ++i){
		digit[i] = i - 'a' + 36;
	}

	while(scanf("%s%d", str, &k) == 2){
		s = 0;
		for(i = 0; str[i]; ++i){
			s *= k;
			s += digit[str[i]];
		}

		fcc = 0;
		i = 0;
		while(true){
			if(k < prime[i]){
				break;
			}

			if(k % prime[i]){
				++i;
			}else{
				f[fcc] = prime[i];
				fc[fcc] = 0;
				while(k % prime[i] == 0){
					k /= prime[i];
					++fc[fcc];
				}
				++fcc;
				++i;
			}
		}

		sum = 0;
		for(i = 0; i < fcc; ++i){
			p = 1;
			cc[i] = 0;
			while(s / f[i] >= p){
				p = p * f[i];
				cc[i] += s / p;
			}
			cc[i] /= fc[i];
		}

		sum = cc[0];
		for(i = 1; i < fcc; ++i){
			if(cc[i] < sum){
				sum = cc[i];
			}
		}

		printf("%lld\n", sum);
	}

	return 0;
}
