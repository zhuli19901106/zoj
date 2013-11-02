#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

typedef struct node{
	string name;
	int day_on_diet;
	int start_weight;
	int current_weight;
}Node;

int comp(const void *a, const void *b)
{
	const Node *na, *nb;
	
	na = (const Node *)a;
	nb = (const Node *)b;
	
	return na->current_weight < nb-> current_weight;
}

int main()
{
	string s;
	Node a[50];
	int i, n;
	int case_count;
	
	case_count = 0;
	while(cin >> s){
		n = 0;
		while(true){
			cin >> a[n].name;
			if(a[n].name == "END"){
				break;
			}else{
				cin >> a[n].day_on_diet >> a[n].start_weight;
				a[n].current_weight = a[n].start_weight - a[n].day_on_diet;
				++n;
			}
		}
		qsort(a, n, sizeof(Node), comp);
		++case_count;
		
		if(case_count > 1){
			cout << endl;
		}
		for(i = 0; i < n; ++i){
			cout << a[i].name << endl;
		}
	}
	
	return 0;
}

