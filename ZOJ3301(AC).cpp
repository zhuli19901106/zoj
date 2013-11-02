#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef struct item{
	int key;
	int id;
}item;

int comparator(const void *a, const void *b)
{
	return ((item *)a)->key - ((item *)b)->key;
}

int main(int argc, char *argv[])
{
	int i;
	int n;
	item a[10000];
	int cases;

	cases = 0;
	while(scanf("%d", &n) == 1){
		cases++;
		if(cases > 1){
			printf("\n");
		}

		for(i = 0; i < n; i++){
			scanf("%d", &a[i].key);
			a[i].id = i + 1;
		}

		qsort(a, n, sizeof(item), comparator);
		for(i = 0; i < n; i = i + 2){
			printf("%d %d\n", a[i].id, a[i + 1].id);
		}
	}

	return 0;
}

