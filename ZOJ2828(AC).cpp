#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

void swap(char &a, char &b)
{
	char tmp;
	
	tmp = a;
	a = b;
	b = tmp;
}

int main()
{
	int t, ti;
	int n;
	int m;
	int i, j;
	map<string, int> mm;
	map<string, int>::iterator mit;
	vector<string> v;
	vector<string>::iterator vit;
	string query, str;
	char buffer[1000];
	int len;
	int found_count;
	
	while(cin >> t){
		for(ti = 0; ti < t; ++ti){
			if(ti > 0){
				cout << endl;
			}
			mm.clear();
			cin >> n;
			for(i = 0; i < n; ++i){
				cin >> str;
				mm.insert(pair<string, int>(str, 0));
			}
			cin >> m;
			for(i = 0; i < m; ++i){
				cin >> query;
				strcpy(buffer, query.data());
				len = strlen(buffer);
				if(mm.find(query) != mm.end()){
					cout << query << endl;
				}else{
					found_count = 0;
					v.clear();
					for(j = 0; j < len - 1; ++j){
						swap(buffer[j], buffer[j + 1]);
						str = string(buffer);
						if(mm.find(str) != mm.end()){
							v.push_back(str);
							++found_count;
						}
						swap(buffer[j], buffer[j + 1]);
					}
					
					if(found_count > 0){
						sort(v.begin(), v.end());
						for(j = 0; j < found_count; ++j){
							if(j == 0){
								cout << v[j];
							}else{
								cout << "," << v[j];
							}
						}
						cout << endl;
					}else{
						cout << query << endl;
					}
				}
			}
		}
	}
	
	return 0;
}

