#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

struct item{
	string name;
	int year;
	int price;
};

int comp_name(const void *a, const void *b)
{
	const struct item *ia, *ib;

	ia = (const struct item *)a;
	ib = (const struct item *)b;
	if(ia->name == ib->name){
		if(ia->price == ib->price){
			return ia->year > ib->year;
		}else{
			return ia->price > ib->price;
		}
	}else{
		return ia->name > ib->name;
	}
}

int comp_year(const void *a, const void *b)
{
	const struct item *ia, *ib;

	ia = (const struct item *)a;
	ib = (const struct item *)b;
	if(ia->year == ib->year){
		if(ia->name == ib->name){
			return ia->price > ib->price;
		}else{
			return ia->name > ib->name;
		}
	}else{
		return ia->year > ib->year;
	}
}

int comp_price(const void *a, const void *b)
{
	const struct item *ia, *ib;

	ia = (const struct item *)a;
	ib = (const struct item *)b;
	if(ia->price == ib->price){
		if(ia->year == ib->year){
			return ia->name > ib->name;
		}else{
			return ia->year > ib->year;
		}
	}else{
		return ia->price > ib->price;
	}
}

int main()
{
	struct item a[102];
	int i, n;
	string sort_criteria;
	int case_count;

	case_count = 0;
	while(cin >> n && n){
		++case_count;
		for(i = 0; i < n; ++i){
			cin >> a[i].name >> a[i].year >> a[i].price;
		}
		cin >> sort_criteria;
		if(sort_criteria == "Name"){
			qsort(a, n, sizeof(struct item), comp_name);
		}else if(sort_criteria == "Year"){
			qsort(a, n, sizeof(struct item), comp_year);
		}else if(sort_criteria == "Price"){
			qsort(a, n, sizeof(struct item), comp_price);
		}

		if(case_count > 1){
			cout << endl;
		}
		for(i = 0; i < n; ++i){
			cout << a[i].name << " " << a[i].year << " " << a[i].price << endl;
		}
	}

	return 0;
}
