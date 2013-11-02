#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main()
{
	map<string, int> mm;
	map<string, int>::iterator it;
	vector<string> v[100], res;
	string file[100], str;
	bool include[100];
	int i, j;
	int n, m;
	int case_count;
	
	case_count = 0;
	while(cin >> n){
		++case_count;
		
		mm.clear();
		for(i = 0; i < n; ++i){
			cin >> file[i];
			include[i] = true;
			mm.insert(pair<string, int>(file[i], i));
			cin >> m;
			v[i].clear();
			for(j = 0; j < m; ++j){
				cin >> str;
				v[i].push_back(str);
			}
		}
		
		for(i = 0; i < n; ++i){
			for(j = 0; j < (int)v[i].size(); ++j){
				it = mm.find(v[i][j]);
				if(it != mm.end()){
					if(include[it->second]){
						include[it->second] = false;
					}
				}
			}
		}
		
		if(case_count > 1){
			cout << endl;
		}
		res.clear();
		for(i = 0; i < n; ++i){
			if(include[i]){
				res.push_back(file[i]);
			}
		}
		sort(res.begin(), res.end());
		for(i = 0; i < (int)res.size(); ++i){
			cout << res[i] << endl;
		}
	}
	
	return 0;
}

