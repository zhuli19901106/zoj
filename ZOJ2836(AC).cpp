#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

int a[100];
int ac;
int n, m;
int sum;

int comp(const void *a, const void *b)
{
	return *(const int *)a - *(const int *)b;
}

int gcd(int a, int b)
{
	if(a < 0){
		return -gcd(-a, b);
	}else if(b < 0){
		return -gcd(a, -b);
	}
	
	if(a == b){
		return a;
	}
	
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

int lcm(int a, int b)
{
	return a / gcd(a, b) * b;
}

void dfs(int idx, int flag, int multiple)
{
	int tmp;
	int i;
	
	for(i = idx; i < ac; ++i){
		tmp = lcm(a[i], multiple);
		sum += flag * m / tmp;
		dfs(i + 1, -flag, tmp);
	}
}

int main()
{
	int case_count;
	int i, j;
	int b[100];
	
	case_count = 0;
	while(true){
		if(scanf("%d%d", &n, &m) != 2){
			break;
		}else{
			++case_count;
		}
		ac = 0;
		for(i = 0; i < n; ++i){
			scanf("%d", &b[i]);
		}
		qsort(b, n, sizeof(int), comp);
		ac = 0;
		for(i = 0; i < n; ++i){
			for(j = 0; j < ac; ++j){
				if(b[i] % a[j] == 0){
					break;
				}
			}
			
			if(j == ac){
				a[ac] = b[i];
				++ac;
			}
		}
		sum = 0;
		dfs(0, 1, 1);
		printf("%d\n", sum);
	}
	
	return 0;
}

