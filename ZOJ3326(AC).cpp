#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef struct date_t{
	int year;
	int month;
	int day;
}date_t;

bool equals(const date_t &a, const date_t &b)
{
	return a.year == b.year && a.month == b.month && a.day == b.day;
}

bool isprime(const int &n)
{
	int i;

	if(n <= 1){
		return false;
	}else if(n == 2){
		return true;
	}else{
		for(i = 2; i * i <= n; i++){
			if(n % i == 0){
				return false;
			}
		}

		return true;
	}
}

bool isleap(const int &year)
{
	return (year % 100 != 0 && year % 4 == 0) || (year % 400 == 0);
}

void next(date_t *d)
{
	int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	days[2] = 28;
	if(isleap(d->year)){
		days[2]++;
	}

	if(d->day == days[d->month]){
		d->day = 1;
		d->month++;
		if(d->month == 13){
			d->month = 1;
			d->year++;
		}
	}else{
		d->day++;
	}
}

bool valid(const date_t &d)
{
	return isprime(d.month) && isprime(d.day);
}

int main()
{
	int t;
	int ans;
	date_t x;
	date_t a;
	date_t b;

	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d", &a.year, &a.month, &a.day);
		scanf("%d%d%d", &b.year, &b.month, &b.day);
		ans = 0;
		x = a;
		while(true){
			if(equals(x, b)){
				break;
			}else{
				if(valid(x)){
					ans++;
				}
				next(&x);
			}
		}
		if(valid(x)){
			ans++;
		}

		printf("%d\n", ans);
	}

	return 0;
}

