#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

bool success;
bool avalid, bvalid;
int v[101];

void swap(int &a, int &b)
{
	int t;
	
	t = a;
	a = b;
	b = t;
}

void dfs(int a, int ai, int b, int bi)
{
	int i;
	
	if(a == 1){
		avalid = true;
	}
	
	if(b == 1){
		bvalid = true;
	}
	
	if(a == 1 && b == 1){
		avalid = true;
		bvalid = true;
		success = true;
		return;
	}
	
	if(a >= ai){
		for(i = ai; i <= 100; ++i){
			if(a % i == 0 && !v[i]){
				v[i] = 1;
				dfs(a / i, i, b, bi);
				v[i] = 0;
			}
		}
	}
	
	if(b >= bi){
		for(i = bi; i <= 100; ++i){
			if(b % i == 0 && !v[i]){
				v[i] = 1;
				dfs(a, ai, b / i, i);
				v[i] = 0;
			}
		}
	}
}

int main()
{
	int a, b;
	
	while(true){
		if(scanf("%d%d", &a, &b) != 2){
			break;
		}
		
		success = false;
		avalid = false;
		bvalid = false;
		if(a > b){
			swap(a, b);
		}
		memset(v, 0, 100 * sizeof(int));
		dfs(a, 2, b, 2);
		if(avalid && bvalid){
			if(success){
				printf("%d\n", b);
			}else{
				printf("%d\n", a);
			}
		}else if(avalid && !bvalid){
			printf("%d\n", a);
		}else if(!avalid && bvalid){
			printf("%d\n", b);
		}else{
			printf("%d\n", b);
		}
	}
	
	return 0;
}

