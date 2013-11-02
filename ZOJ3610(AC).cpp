#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	int t;
	char a[1000];
	char b[1000];
	char c[1000];

	scanf("%d", &t);
	while(t--){
		scanf("%s%s%s", a, b, c);

		printf("%s will survive\n", b);
	}

	return 0;
}

