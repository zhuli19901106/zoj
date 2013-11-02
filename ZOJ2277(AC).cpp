#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	int n;

	while(scanf("%d", &n) == 1){
		printf("%d\n", (int)pow(10, ((n * log10(1.0 * n)) - floor(n * log10(1.0 * n)))));
	}

	return 0;
}

