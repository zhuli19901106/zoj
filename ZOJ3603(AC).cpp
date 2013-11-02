#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef unsigned long dword;
#define MASK_A 
#define MASK_B 
#define MASK_C 
#define MASK_D 
#define MASK_E 
#define MASK_F 
#define MASK_G 
#define MASK_H 
#define MASK_I 
#define MASK_J 
#define MASK_K 
#define MASK_L 
#define MASK_M 
#define MASK_N 
#define MASK_O 
#define MASK_P 
#define MASK_Q 
#define MASK_R 
#define MASK_S 
#define MASK_T 
#define MASK_U 
#define MASK_V 
#define MASK_W 
#define MASK_X 
#define MASK_Y 
#define MASK_Z 

int main()
{
	int t;
	int n;
	int ni;
	int i;
	int j;
	char str[1000];
	int a[26];
	int b[26];

	scanf("%d", &t);
	while(t--){
		for(i = 0; i < 26; i++){
			a[i] = -1;
		}

		scanf("%d", &n);
		for(ni = 0; ni < n; ni++){
			scanf("%s", str);

			for(i = 0; i < 26; i++){
				b[i] = 0;
			}

			for(i = 0; str[i] != 0; i++){
				b[str[i] - 'A']++;
			}

			for(i = 0; i < 26; i++){
				if(a[i] == -1 || b[i] < a[i]){
					a[i] = b[i];
				}
			}
		}
		for(i = 0; i < 26; i++){
			for(j = 0; j < a[i]; j++){
				printf("%c", i + 'A');
			}
		}
		printf("\n");
	}

	return 0;
}

