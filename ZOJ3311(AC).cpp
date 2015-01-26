#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
	char str[1000];
	int i;
	int zc, jc;
	int oc1, oc2;
	bool success;
	
	while(true){
		if(gets(str) == NULL){
			break;
		}
		
		success = true;
		zc = 0;
		jc = 0;
		oc1 = 0;
		oc2 = 0;
		for(i = 0; success && str[i] != 0; ++i){
			switch(str[i]){
				case 'Z':
					if(zc > 0){
						success = false;
					}else{
						++zc;
					}
					break;
				case 'O':
					if(zc == 1 && jc == 0){
						++oc1;
					}else if(zc == 1 && jc == 1){
						++oc2;
					}
					break;
				case 'J':
					if(zc == 1){
						++jc;
					}else{
						success = false;
					}
					break;
				default:
					success = false;
					break;
			}
		}
		if(oc1 < 1 || oc2 < 1 || oc1 > oc2){
			success = false;
		}
		
		if(success){
			printf("Accepted\n");
		}else{
			printf("Wrong Answer\n");
		}
	}
	
	return 0;
}
