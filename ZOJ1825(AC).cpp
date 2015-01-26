#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
	map<string, int> mm;
	map<string, int>::iterator it;
	string str;
	string left, right;
	int len;
	int i;
	bool is_compound;

	while(cin >> str){
		mm.insert(pair<string, int>(str, 1));
	}
	for(it = mm.begin(); it != mm.end(); it++){
		is_compound = false;
		str = it->first;
		len = str.length();
		for(i = 1; i <= len - 1; i++){
			left = str.substr(0, i);
			right = str.substr(i, len - i);
			if(mm.find(left) != mm.end() && mm.find(right) != mm.end()){
				is_compound = true;
			}
		}
		if(is_compound){
			cout << str << endl;
		}
	}

	return 0;
}
