#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

void reverse(char s[])
{
	char tmp;
	int i, j;
	int len;
	
	len = strlen(s);
	i = 0;
	j = len - 1;
	while(i < j){
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
		++i;
		--j;
	}
}

int main()
{
	char s[1000];
	int a[100];
	int sum[100];
	int i, j, len;
	int n, ni;
	
	while(true){
		if(gets(s) == NULL){
			break;
		}
		sscanf(s, "%d", &n);
		if(0 == n){
			break;
		}
		memset(sum, 0, 100 * sizeof(int));
		for(ni = 0; ni < n; ++ni){
			memset(a, 0, 100 * sizeof(int));
			gets(s);
			if(strcmp(s, "$0.00") == 0){
				continue;
			}
			
			len = strlen(s);
			j = 0;
			for(i = len - 1; i >= 0; --i){
				if(s[i] >= '0' && s[i] <= '9'){
					a[j++] = s[i] - '0';
				}
			}
			for(i = 0; i < 100; ++i){
				sum[i] = sum[i] + a[i];
			}
			for(i = 0; i < 99; i++){
				sum[i + 1] += sum[i] / 10;
				sum[i] %= 10;
			}
			sum[99] %= 10;
		}

		i = 99;
		while(i >= 0 && sum[i] == 0){
			--i;
		}
		if(i == -1){
			printf("$0.00\n");
		}else if(i <= 1){
			printf("$0.%d%d\n", sum[1], sum[0]);
		}else{
			len = i;
			j = 0;
			for(i = 0; i <= len; ++i){
				s[j++] = sum[i] + '0';
				if(i == 1){
					s[j++] = '.';
				}else if(i == len){
					s[j++] = '$';
				}else if(i > 1 && (i - 1) % 3 == 0){
					s[j++] = ',';
				}
			}
			s[j] = 0;
			reverse(s);
			puts(s);
		}
	}
	
	return 0;
}

