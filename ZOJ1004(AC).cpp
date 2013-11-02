#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>
using namespace std;

vector<string> res;
map<string, int> mm;
string a, b;
int sa, sb;
char s[2000];

void dfs(int x, int y, int len, stack<char> st, bool bb)
{
	while(y < sb){
		if(!st.empty() && y < sb && st.top() == b[y]){
			while(!st.empty() && y < sb && st.top() == b[y]){
				if(x < sa){
					st.push(a[x++]);
					s[len++] = 'i';
					s[len++] = ' ';
					dfs(x, y, len, stack<char>(st), true);
					--len;
					--len;
					--x;
					st.pop();
				}

				st.pop();
				s[len++] = 'o';
				s[len++] = ' ';
				++y;
			}
		}else if(x < sa && a[x] == b[y]){
			while(x < sa && a[x] == b[y]){
				st.push(a[x++]);
				s[len++] = 'i';
				s[len++] = ' ';
				dfs(x, y, len, stack<char>(st), true);
				--len;
				--len;
				--x;
				st.pop();

				++x;
				++y;
				s[len++] = 'i';
				s[len++] = ' ';
				s[len++] = 'o';
				s[len++] = ' ';
			}
		}else if(x < sa){
			st.push(a[x++]);
			s[len++] = 'i';
			s[len++] = ' ';
		}else{
			break;
		}
		bb = false;
	}
	if(x >= sa && y >= sb && st.empty())
	{
		s[len] = 0;
		string str = string(s);
		if(mm.find(s) == mm.end()){
			res.push_back(str);
			mm.insert(pair<string, int>(str, (int)res.size()));
		}
	}
}

int main()
{ 
	int ct[26];
	int i;
	int tmp;
	stack<char> sta;

	while(cin >> a >> b){
		res.clear();
		memset(ct, 0, 26 * sizeof(int));
		if(a.size() != b.size()){
			cout << "[" << endl;
			cout << "]" << endl;
			continue;
		}
		tmp = a.size();
		for(i = 0; i < tmp; ++i){
			if(a[i] >= 'a' && a[i] <= 'z'){
				++ct[a[i] - 'a'];
			}
		}
		tmp = b.size();
		for(i = 0; i < tmp; ++i){
			if(b[i] >= 'a' && b[i] <= 'z'){
				--ct[b[i] - 'a'];
			}
		}
		for(i = 0; i < 26; ++i){
			if(ct[i]){
				break;
			}
		}
		if(i < 26){
			cout << "[" << endl;
			cout << "]" << endl;
			continue;
		}
		
		while(!sta.empty()){
			sta.pop();
		}
		res.clear();
		mm.clear();
		sa = a.size();
		sb = b.size();
		dfs(0, 0, 0, sta, false);
		sort(res.begin(), res.end());
		cout << "[" << endl;
		tmp = res.size();
		for(i = 0; i < tmp; ++i){
			cout << res[i] << endl;
		}
		cout << "]" << endl;
	}
	
	return 0;
}

