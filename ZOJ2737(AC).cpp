#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
	string x, y;
	string str;
	map<string, int> msi;
	map<int, string> mis;
	string ss[100];
	int i;
	int sc;
	int x_size;
	int y_size;
	
	while(cin >> x >> y){
		x_size = x.size();
		y_size = y.size();
		msi.clear();
		mis.clear();
		sc = 0;
		msi.insert(pair<string, int>(y, sc));
		mis.insert(pair<int, string>(sc, y));
		++sc;
		for(i = 1; i < y_size; ++i){
			str = y.substr(i, y_size - i) + y.substr(0, i);
			if(msi.find(str) == msi.end()){
				msi.insert(pair<string, int>(str, sc));
				mis.insert(pair<int, string>(sc, str));
				++sc;
			}
		}

		if(x_size < y_size){
			cout << 0 << endl;
		}else{
			int count = 0;
			for(i = 0; i + y_size <= x_size; ++i){
				str = x.substr(i, y_size);
				if(msi.find(str) != msi.end()){
					++count;
				}
			}
			
			cout << count << endl;
		}
	}

	return 0;
}

