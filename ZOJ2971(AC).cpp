#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

char s[1000];
char temp[1000];
vector<string> vs;
int n, sum;
string ones[10] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
string tys[10] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
string tens[10] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

int main()
{
	int t, ti;
	int i, j, len;

	while(gets(s) != NULL && sscanf(s, "%d", &t) == 1){
		for(ti = 0; ti < t; ++ti){
			gets(s);
			i = 0;
			len = strlen(s);
			vs.clear();
			while(i < len){
				while(i < len && s[i] == ' '){
					++i;
				}
				if(i >= len){
					break;
				}
				j = 0;
				while(i < len && s[i] != ' '){
					temp[j++] = s[i++];
				}
				temp[j] = 0;
				if(strlen(temp) > 0){
					vs.push_back(string(temp));
				}
			}

			n = sum = 0;
			for(i = 0; i < (int)vs.size(); ++i){
				for(j = 1; j < 10; ++j){
					if(vs[i] == ones[j]){
						n += j;
						break;
					}
				}
				if(j < 10){
					continue;
				}
				for(j = 2; j <10; ++j){
					if(vs[i] == tys[j]){
						n += j * 10;
						break;
					}
				}
				if(j < 10){
					continue;
				}
				for(j = 0; j < 10; ++j){
					if(vs[i] == tens[j]){
						n += (10 + j);
						break;
					}
				}
				if(j < 10){
					continue;
				}
				if(vs[i] == "hundred"){
					n *= 100;
				}else if(vs[i] == "thousand"){
					sum += n * 1000;
					n = 0;
				}else if(vs[i] == "million"){
					sum += n * 1000000;
					n = 0;
				}else{
					//ignored
				}
			}
			if(n > 0){
				sum += n;
				n = 0;
			}

			printf("%d\n", sum);
		}
	}

	return 0;
}

