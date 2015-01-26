#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef struct st{
	string id;
	string name;
	int grade;
}st;

bool comp1(const st &a, const st &b)
{
	return a.id < b.id;
}

bool comp2(const st &a, const st &b)
{
	if(a.name == b.name){
		return a.id < b.id;
	}else{
		return a.name < b.name;
	}
}

bool comp3(const st &a, const st &b)
{
	if(a.grade == b.grade){
		return a.id < b.id;
	}else{
		return a.grade < b.grade;
	}
}

vector<st> v;
int n, c;

int main()
{
	int i;
	char s[20];
	st t;
	
	while(scanf("%d%d", &n, &c) == 2){
		v.clear();
		for(i = 0; i < n; ++i){
			scanf("%s", s);
			t.id = string(s);
			scanf("%s", s);
			t.name = string(s);
			scanf("%d", &t.grade);
			v.push_back(t);
		}
		switch(c){
			case 1:
				sort(v.begin(), v.end(), comp1);
				break;
			case 2:
				sort(v.begin(), v.end(), comp2);
				break;
			case 3:
				sort(v.begin(), v.end(), comp3);
				break;
		}
		
		for(i = 0; i < n; ++i){
			printf("%s %s %d\n", v[i].id.data(), v[i].name.data(), v[i].grade);
		}
	}
	
	return 0;
}
