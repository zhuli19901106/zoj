#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <string>
using namespace std;

int p, t;
char a[105][105];
map<string, int> mm;
map<string, int>::iterator mit;
char str[1000];

int main()
{
	int i, j;
	int x, y;
	string s;
	int nc;
	char *pstr;
	
	while(true){
		gets(str);
		sscanf(str, "%d%d", &p, &t);
		memset(a, 0, 105 * 105 * sizeof(char));
		while((pstr = gets(str)) != NULL){
			if(!str[0]){
				break;
			}else{
				sscanf(str, "%d%d", &x, &y);
				--x;
				--y;
				a[x][y] = 1;
			}
		}

		mm.clear();
		nc = 0;
		for(i = 0; i < p; ++i){
			for(j = 0; j < t; ++j){
				a[i][j] += '0';
			}
			s = string(a[i]);
			mit = mm.find(s);
			if(mit == mm.end()){
				mm.insert(pair<string, int>(s, 0));
				++nc;
			}
		}
		printf("%d\n", nc);

		if(!pstr){
			break;
		}
	}

	return 0;
}

