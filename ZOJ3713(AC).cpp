#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

char s[3000005];
char str[6000010];
int len;

inline char hex_char(int d)
{
	if(d >= 0 && d <= 9){
		return d + '0';
	}else{
		return d - 10 + 'A';
	}
}

int main()
{
	int byte;
	int t, ti;
	int i, j;

	while(gets(s) != NULL && sscanf(s, "%d", &t) == 1){
		for(ti = 0; ti < t; ++ti){
			gets(s);
			len = strlen(s);
			while(true){
				byte = len & 0x7f;
				len >>= 7;
				if(len > 0){
					byte |= 0x80;
					printf("%02X", byte);
				}else{
					printf("%02X", byte);
					break;
				}
			}
			j = 0;
			for(i = 0; s[i]; ++i){
				str[j++] = hex_char(s[i] >> 4);
				str[j++] = hex_char(s[i] & 0xf);
			}
			str[j] = 0;
			puts(str);
		}
	}

	return 0;
}

