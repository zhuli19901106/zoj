#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <string>
using namespace std;

struct item{
	int price;
	int count;
	int name_index;
};

int comp(const void *a, const void *b)
{
	const struct item *ia, *ib;

	ia = (const struct item *)a;
	ib = (const struct item *)b;

	if(ia->count == ib->count){
		return ia->price > ib->price;
	}else{
		return ia->count > ib->count;
	}
}

int main()
{
	struct item a[10010];
	map<string, int> m1;
	map<int, string> m2;
	int name_count;
	int t, ti;
	int u, m;
	int i;
	int price;
	string name;

	cin >> t;
	for(ti = 1; ti <= t; ++ti){
		cin >> u >> m;
		for(i = 0; i < 10010; ++i){
			a[i].price = i;
			a[i].count = 0;
			a[i].name_index = -1;
		}

		for(i = 0; i < m; ++i){
			cin >> name >> price;
			++(a[price].count);
			if(m1.find(name) == m1.end()){
				m1.insert(pair<string, int>(name, name_count));
				m2.insert(pair<int, string>(name_count, name));
				++name_count;
			}
			if(a[price].name_index == -1){
				a[price].name_index = m1.find(name)->second;
			}
		}

		qsort(a, 10010, sizeof(struct item), comp);
		i = 0;
		while(a[i].count == 0){
			++i;
		}

		if(ti > 1){
			cout << endl;
		}
		cout << "Case " << ti << ":" << endl;
		cout << "The winner is " << m2.find(a[i].name_index)->second << "." << endl;
		cout << "The price is " << a[i].price << "." << endl;
	}

	return 0;
}
