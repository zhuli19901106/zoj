#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

char mat[11][8][9] = {
	{
		"  XXXX  ",
		" XX  XX ",
		" XX  XX ",
		" XX  XX ",
		" XX  XX ",
		" XX  XX ",
		" XX  XX ",
		"  XXXX  "
	}, {
		"   XX   ",
		" XXXX   ",
		"   XX   ",
		"   XX   ",
		"   XX   ",
		"   XX   ",
		"   XX   ",
		" XXXXXX ",
	}, {
		"  XXXX  ",
		" XX  XX ",
		" XX  XX ",
		"     XX ",
		"    XX  ",
		"   XX   ",
		"  XX    ",
		" XXXXXX "
	}, {
		"  XXXX  ",
		" X   XX ",
		"     XX ",
		"   XXX  ",
		"     XX ",
		"     XX ",
		" X   XX ",
		"  XXXX  "
	}, {
		"    XX  ",
		"   XXX  ",
		"   XXX  ",
		"  X XX  ",
		" X  XX  ",
		" XXXXXX ",
		"    XX  ",
		"  XXXXX "
	}, {
		"  XXXXX ",
		"  XX    ",
		"  XXXX  ",
		"  X  XX ",
		"     XX ",
		"     XX ",
		" X   XX ",
		"  XXXX  "
	}, {
		"   XXXX ",
		"  XX    ",
		" XX     ",
		" XXXXX  ",
		" XX  XX ",
		" XX  XX ",
		" XX  XX ",
		"  XXXX  "
	}, {
		" XXXXXX ",
		" X   XX ",
		"     XX ",
		"    XX  ",
		"    XX  ",
		"    XX  ",
		"   XX   ",
		"   XX   "
	}, {
		"  XXXX  ",
		" XX  XX ",
		" XX  XX ",
		"  XXXX  ",
		" XX  XX ",
		" XX  XX ",
		" XX  XX ",
		"  XXXX  "
	}, {
		"  XXXX  ",
		" XX  XX ",
		" XX  XX ",
		" XX  XX ",
		"  XXXXX ",
		"     XX ",
		"    XX  ",
		" XXXX   "
	}, {
		"        ",
		"   X    ",
		"   X    ",
		"   X    ",
		"XXXXXXX ",
		"   X    ",
		"   X    ",
		"   X    "
	}
};

char m[8][9];
char s[8][1500];
int lens[8];
char str[1500];

int main()
{
	int i, j, k;
	int case_count, case_no;
	int pos;
	int len, min_len;
	int cstr;
	int a, b;
	bool terminate;
	
	while(true){
		if(gets(s[0]) == NULL){
			break;
		}else if(sscanf(s[0], "%d", &case_count) != 1){
			continue;
		}
		for(case_no = 0; case_no < case_count; ++case_no){
			if(case_no > 0){
				//There is a blank line between consecutive test cases.
				//Cost me 3WAs..., scheisse~
				gets(s[0]);
			}
			min_len = 100000;
			for(i = 0; i < 8; ++i){
				gets(s[i]);
				lens[i] = strlen(s[i]);
				if(lens[i] < min_len){
					min_len = lens[i];
				}
			}
			
			pos = 0;
			len = strlen(s[0]);
			cstr = 0;
			while(true){
				if(pos + 1 >= min_len){
					break;
				}
				for(i = 0; i < 8; ++i){
					if(s[i][pos] != ' ' || s[i][pos + 1] != ' '){
						break;
					}
				}
				if(i == 8){
					++pos;
				}else{
					if(
						s[i][pos] == ' '
						&& s[i][pos + 1] == 'X' 
						&& s[i][pos + 2] == 'X' 
						&& s[i][pos + 3] == 'X' 
						&& s[i][pos + 4] == 'X'
						&& s[i][pos + 5] == 'X'
						&& s[i][pos + 6] == 'X'
						&& s[i][pos + 7] == 'X'
						&& s[i][pos + 8] == ' '
					){
						++pos;
					}
					
					for(i = 0; i < 8; ++i){
						for(j = 0; j < 8; ++j){
							if(pos + j < lens[i]){
								m[i][j] = s[i][pos + j];
							}else{
								m[i][j] = ' ';
							}
						}
						m[i][j] = 0;
					}
					
					terminate = false;
					for(i = 0; i < 11; ++i){
						for(j = 0; j < 8; ++j){
							for(k = 0; k < 8; ++k){
								if(m[j][k] != mat[i][j][k]){
									break;
								}
							}
							if(k < 8){
								break;
							}
						}
						if(j == 8 && k == 8){
							break;
						}
					}
					if(i >= 0 && i <= 9){
						str[cstr] = i + '0';
						++cstr;
					}else if(i == 10){
						str[cstr] = '+';
						++cstr;
					}
					
					pos += 8;
				}
			}
			str[cstr] = 0;
			a = 0;
			b = 0;
			i = 0;
			while(true){
				if(str[i] >= '0' && str[i] <= '9'){
					b = b * 10 + str[i] - '0';
				}else if(str[i] == '+'){
					a += b;
					b = 0;
				}else if(str[i] == 0){
					a += b;
					b = 0;
					break;
				}
				++i;
			}
			sprintf(str, "%d", a);
			len = strlen(str);
			for(i = 0; i < 8; ++i){
				for(j = 0; j < 8; ++j){
					for(k = 0; k < len; ++k){
						s[i][k * 8 + j] = mat[str[k] - '0'][i][j];
					}
				}
				s[i][8 * len] = 0;
			}
			if(case_no > 0){
				printf("\n");
			}
			for(i = 0; i < 8; ++i){
				printf("%s\n", s[i]);
			}
		}
	}
	
	return 0;
}
