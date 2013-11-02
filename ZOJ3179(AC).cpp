#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
	int x;
	int y;
	int i;
	int j;
	int t;
	int sum;
	char digits[10];
	char input[10][7];
	char check[10][10];
	char ans[10][10];
	char s[10][10] = {
		"o|-|oooo",
		"o|-o|ooo",
		"o|-oo|oo",
		"o|-ooo|o",
		"o|-oooo|",
		"|o-|oooo",
		"|o-o|ooo",
		"|o-oo|oo",
		"|o-ooo|o",
		"|o-oooo|"
	};

	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &x, &y);
		sum = 0;
		for(i = x; i <= y; i++){
			sum = sum + i;
		}
		sprintf(digits, "%06d", sum);

		for(i = 0; i < 8; i++){
			scanf("%s", input[i]);
		}

		for(i = 0; i < 9; i++){
			for(j = 0; j < 6; j++){
				if(i == 8){
					ans[j][i] = 0;
				}else{
					ans[j][i] = input[i][j];
				}
			}
		}

		for(i = 0; i <= 6; i++){
			strcpy(check[i], s[digits[i] - '0']);			
		}

		for(i = 0; i < 6; i++){
			if(strcmp(check[i], ans[i]) != 0){
				break;
			}
		}

		if(i == 6){
			printf("No mistake\n");
		}else{
			printf("Mistake\n");
		}
	}

	return 0;
}

