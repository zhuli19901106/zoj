#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
using namespace std;

int b[510000];
int p[300000], pc;
map<int, int> mm;

int main()
{
	int i, j;
	int n;
	
	memset(b, 0, 510000 * sizeof(int));
	b[0] = 1;
	b[1] = 1;
	for(i = 2; i < 1000; ++i){
		if(b[i]){
			continue;
		}
		for(j = i; i * j < 510000; ++j){
			b[i * j] = 1;
		}
	}
	
	pc = 0;
	for(i = 0; i < 510000; ++i){
		if(!b[i]){
			p[pc++] = i;
		}
	}
	
	mm.clear();
	for(i = 0; i < 1100; ++i){
		for(j = i; j < pc && p[i] * p[j] <= 1000000; ++j){
			if(mm.find(p[i] * p[j]) == mm.end()){
				mm.insert(pair<int, int>(p[i] * p[j], 0));
			}
		}
	}
	
	while(scanf("%d", &n) == 1){
		if(mm.find(n) != mm.end()){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}
	
	return 0;
}
