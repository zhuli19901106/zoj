#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef struct roman_t{
	int val;
	char roman_name[50];
}roman_t;

int comparator(const void *a, const void *b)
{
	return strcmp(((roman_t *)a)->roman_name, ((roman_t *)b)->roman_name);
}

void parse_name(roman_t *r)
{
	int d[4];
	int dc;
	int n;
	int i;
	char s[4][10][10] = {
		{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
		{"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
		{"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
		{"", "M", "MM", "MMM", "", "", "", "", "", ""}
	};
	char result[100];

	n = r->val;
	dc = 0;
	while(n > 0){
		d[dc] = n % 10;
		dc++;
		n = n / 10;
	}

	result[0] = 0;
	for(i = dc - 1; i >= 0; i--){
		strcat(result, s[i][d[i]]);
	}

	//printf("%s\n", result);
	strcpy(r->roman_name, result);
}

int main()
{
	int i;
	int n;
	int t;
	roman_t *a = NULL;

	a = (roman_t *)malloc(10001 * sizeof(roman_t));
	if(a == NULL){
		fprintf(stderr, "Failed to allocate memory.\n");
		exit(1);
	}
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(i = 0; i < n; i++){
			scanf("%d", &a[i].val);
			parse_name(&a[i]);
		}

		qsort(a, n, sizeof(roman_t), comparator);
		for(i = 0; i < n; i++){
			if(i > 0){
				printf(" ");
			}
			printf("%d", a[i].val);
		}
		printf("\n");
	}

	free(a);
	a = NULL;

	return 0;
}

