#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int abs(int n)
{
	return (n > 0 ? n : -n);
}

int main()
{
	char s[1000];
	int a[1000];
	int i;
	int ac;
	int cp, d1, d2;
	bool minus;
	int case_no;
	
	case_no = 0;
	while(true){
		if(gets(s) == NULL){
			break;
		}
		ac = 0;
		i = 0;
		while(true){
			if(s[i] == 0){
				break;
			}else{
				a[ac] = 0;
				minus = false;
				while(s[i] < '0' || s[i] > '9'){
					if(s[i] == 0){
						break;
					}else if(s[i] == '-'){
						minus = true;
					}
					++i;
				}
				while(s[i] >= '0' && s[i] <= '9'){
					a[ac] = a[ac] * 10 + s[i] - '0';
					++i;
				}
				if(minus){
					a[ac] = -a[ac];
				}
				++ac;
			}
		}

		if(a[0] == 5280){
			break;
		}else{
			++case_no;
		}

		if(case_no > 1){
			printf("\n");
		}
		cp = 0;
		for(i = 1; i < ac; ++i){
			d1 = abs(cp - a[0]);
			d2 = abs(a[i] - a[0]);
			printf("Moving from %d to %d: ", cp, a[i]);
			cp = a[i];
			if(cp == a[0]){
				printf("found it!\n");
			}else if(d1 < d2){
				printf("colder.\n");
			}else if(d1 > d2){
				printf("warmer.\n");
			}else{
				printf("same.\n");
			}
		}
	}
	
	return 0;
}
