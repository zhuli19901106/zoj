#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
	char str[100010];
	char sc[100010];
	int si[100010];
	int sp;
	int len;
	int left, right;
	int lleft, lright;
	int max_len;
	
	while(true){
		if(scanf("%s", str) != 1){
			break;
		}
		
		len = strlen(str);
		sp = 0;
		left = 0;
		right = 0;
		lleft = 0;
		lright = -1;
		max_len = lright - lleft + 1;
		while(true){
			if(str[right] == 0){
				break;
			}
			switch(str[right]){
				case '(':
					sc[sp] = str[right];
					si[sp] = right;
					++sp;
					++right;
					break;
				case '[':
					sc[sp] = str[right];
					si[sp] = right;
					++sp;
					++right;
					break;
				case ')':
					if(sc[sp - 1] == '('){
						++right;
						--sp;
						if(sp == 0){
							if(max_len < right - left + 1){
								max_len = right - left + 1;
								lleft = left;
								lright = right;
							}
						}else{
							if(max_len < right - si[sp - 1]){
								max_len = right - si[sp - 1];
								lleft = si[sp - 1] + 1;
								lright = right;
							}
						}
					}else{
						left = right + 1;
						right = left;
						sp = 0;//Clear the stack because the string before this position is invalid.
					}
					break;
				case ']':
					if(sc[sp - 1] == '['){
						++right;
						--sp;
						if(sp == 0){
							if(max_len < right - left + 1){
								max_len = right - left + 1;
								lleft = left;
								lright = right;
							}
						}else{
							if(max_len < right - si[sp - 1]){
								max_len = right - si[sp - 1];
								lleft = si[sp - 1] + 1;
								lright = right;
							}
						}
					}else{
						left = right + 1;
						right = left;
						sp = 0;//Clear the stack because the string before this position is invalid.
					}
					break;
			}
		}

		if(lright != -1){
			str[lright] = 0;
			printf("%s\n\n", str + lleft);
		}else{
			printf("\n\n");
		}
	}
	
	return 0;
}
