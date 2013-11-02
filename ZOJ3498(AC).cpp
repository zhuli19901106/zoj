#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <cstdio>
#include <cstdlib>

int main()
{
	int t, n;
	int ans;

	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		ans = 0;
		while(n > 0){
			ans++;
			n = n / 2;
		}
		printf("%d\n", ans);
	}

	return 0;
}

