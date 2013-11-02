#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	int n;
	int x;
	int count;
	int i;
	int ans;

	while(true){
		if(scanf("%d", &n) != 1){
			break;
		}

		count = 0;
		for(i = 0; i < n; i++){
			scanf("%d", &x);
			if(count == 0){
				ans = x;
				count++;
			}else{
				if(x == ans){
					count++;
				}else{
					count--;
				}
			}
		}

		printf("%d\n", ans);
	}

	return 0;
}

