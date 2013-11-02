#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int gcd(int a, int b)
{
	if(a == b){
		return a;
	}else{
		while(true){
			if(a > b){
				if(a % b == 0){
					return b;
				}else{
					a = a % b;
				}
			}else{
				if(b % a == 0){
					return a;
				}else{
					b = b % a;
				}
			}
		}
	}
}

int main()
{
	int t;
	int a;
	int m;
	int i;

	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &a, &m);
		if(m == 1){
			printf("1\n");
			continue;
		}else if(gcd(a, m) != 1){
			printf("Not Exist\n");
			continue;
		}

		for(i = 1; i < m; i++){
			if((i * a) % m == 1){
				break;
			}
		}

		if(i == m){
			printf("Not Exist\n");
		}else{
			printf("%d\n", i);
		}
	}

	return 0;
}

