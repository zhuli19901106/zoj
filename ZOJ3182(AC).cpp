#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	int a[100];
	int i;
	int case_count, case_no;

	a[0] = 0;
	a[1] = 1;
	a[2] = 2;
	for(i = 3; i < 100; ++i){
		a[i] = a[i - 1] + 2 * a[i - 2] + 1;
	}

	while(scanf("%d", &case_count) == 1){
		for(case_no = 0; case_no < case_count; ++case_no){
			scanf("%d", &i);
			printf("%d\n", a[i]);
		}
	}
	
	return 0;
}
