#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

string files[200];
int n, m;

int main()
{
	int i, j;
	int star;
	int count;
	int case_count;
	string query, front, rear;
	
	case_count = 0;
	while(cin >> n && n){
		++case_count;
		for(i = 0; i < n; ++i){
			cin >> files[i];
		}
		
		cin >> m;
		if(case_count > 1){
			cout << endl;
		}
		for(i = 0; i < m; ++i){
			cin >> query;
			for(star = 0; star < (int)query. size(); ++star){
				if(query[star] == '*'){
					break;
				}
			}
			if(star == query.size()){
				star = -1;
				front = "";
				rear = query;
			}else if(star == 0){
				front = "";
				rear = query.substr(1, query.size() - 1);
			}else if(star == query.size() - 1){
				front = query.substr(0, query.size() - 1);
				rear = "";
			}else{
				front = query.substr(0, star);
				rear = query.substr(star + 1, query.size() - star - 1);
			}

			count = 0;
			for(j = 0; j < n; ++j){
				if(star == -1){
					if(files[j] == query){
						if(count > 0){
							cout << ", " << files[j];
						}else{
							cout << files[j];
						}
						++count;
					}
				}else{
					if(front.size() > 0){
						if(files[j].size() < front.size()){
							continue;
						}else if(files[j].substr(0, front.size()) != front){
							continue;
						}
					}
					
					if(rear.size() >  0){
						if(files[j].size() < rear.size()){
							continue;
						}else if(files[j].substr(files[j].size() - rear.size(), rear.size()) != rear){
							continue;
						}
					}

					if(files[j].size() < front.size() + rear.size()){
						continue;
					}
					
					if(count > 0){
						cout << ", " << files[j];
					}else{
						cout << files[j];
					}
					++count;
				}
			}
			
			if(0 == count){
				cout << "FILE NOT FOUND" << endl;
			}else{
				cout << endl;
			}
		}
	}
	
	return 0;
}

