#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <map>
#include <string>
using namespace std;

int main()
{
	char str[1000];
	char left[1000], right[1000];
	int count;
	map<string, string> dict;
	map<string, string>::iterator it;
	string sleft, sright, word;
	
	dict.clear();
	while(true){
		if(gets(str) == NULL){
			break;
		}
		count = sscanf(str, "%s%s", left, right);
		if(2 == count){
			sleft = string(left);
			sright = string(right);
			dict.insert(pair<string, string>(sright, sleft));
		}else if(1 == count){
			word = string(str);
			it = dict.find(word);
			if(it != dict.end()){
				printf("%s\n", it->second.data());
			}else{
				printf("eh\n");
			}
		}else{
			//do nothing for an empty line.
		}
	}
	
	return 0;
}

