#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXN = 100;
int a[MAXN];
int a0[MAXN];
int b[MAXN];
int bc;
char s[100];
int len;

int main()
{
	int i, j;

	printf("Problem 4 by team x\n");
	while(scanf("%s", s) == 1){
		memset(a, 0, MAXN * sizeof(int));
		memset(b, 0, MAXN * sizeof(int));
		len = strlen(s);
		for(i = 0; i < len; ++i){
			a[i] = s[len - 1 - i] - '0';
		}
		memcpy(a0, a, MAXN * sizeof(int));
		b[0] = 1;
		bc = 0;

		//divide by 5
		while(a[0] % 5 == 0){
			for(i = MAXN - 1; i > 0; --i){
				if(a[i]){
					a[i - 1] += a[i] % 5 * 10;
					a[i] /= 5;
				}
			}
			a[0] /= 5;

			for(i = 0; i < MAXN; ++i){
				b[i] *= 2;
			}
			for(i = 0; i < MAXN - 1; ++i){
				b[i + 1] += b[i] / 10;
				b[i] %= 10;
			}
			++bc;
		}

		//divide by 2
		while(a[0] % 2 == 0){
			for(i = MAXN - 1; i > 0; --i){
				if(a[i]){
					a[i - 1] += a[i] % 2 * 10;
					a[i] /= 2;
				}
			}
			a[0] /= 2;

			for(i = 0; i < MAXN; ++i){
				b[i] *= 5;
			}
			for(i = 0; i < MAXN - 1; ++i){
				b[i + 1] += b[i] / 10;
				b[i] %= 10;
			}
			++bc;
		}

		printf("\n1 / ");
		printf("%s", s);
		printf(" =\n0.");
		
		j = 0;
		while(j <= bc - 1 && b[j] == 0){
			++j;
		}
		for(i = bc - 1; i >= j; --i){
			printf("%d", b[i]);
		}
		printf("\n");
	}
	printf("End of problem 4 by team x\n");

	return 0;
}
