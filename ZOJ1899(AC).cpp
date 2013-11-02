#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <string>
using namespace std;

map<string, int> mm;
map<string, int>::iterator mit;
int n;
char s[100];

int main()
{
	int cc;
	string str;
	char *pstr;

	cc = 0;
	do{
		mm.clear();
		n = 0;
		while((pstr = gets(s)) != NULL){
			if(!s[0]){
				break;
			}
			++n;
			str = string(s);
			mit = mm.find(str);
			if(mit != mm.end()){
				++(mit->second);
			}else{
				mm.insert(pair<string, int>(str, 1));
			}
		}

		if(cc){
			printf("\n");
		}
		for(mit = mm.begin(); mit != mm.end(); ++mit){
			printf("%s %.4f\n", mit->first.data(), 100.0 * mit->second / n);
		}
		++cc;
	}while(pstr);

	return 0;
}

