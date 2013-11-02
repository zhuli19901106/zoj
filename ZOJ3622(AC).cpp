#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef long long int ll;

bool check(ll n)
{
	int c2;
	int c5;
	int dc;
	ll n0;

	c2 = 0;
	c5 = 0;
	n0 = n;
	while(n % 2 == 0){
		c2++;
		n = n / 2;
	}
	n = n0;
	
	while(n % 5 == 0){
		c5++;
		n = n / 5;
	}
	n = n0;

	dc = 0;
	while(n > 0){
		dc++;
		n = n / 10;
	}

	if(c2 <= dc && c5 <= dc){
		return true;
	}else{
		return false;
	}
}

int main()
{
	int i, j;
	ll m;
	ll n;
	int x;
	int count;
	int bcount;
	int result;
	ll a[1000];
	ll b[1000];
	ll b2[11];
	ll b5[11];
	ll tmp;

	b2[0] = b5[0] = 1;
	for(i = 1; i <= 10; i++){
		b2[i] = b2[i - 1] * 2;
		b5[i] = b5[i - 1] * 5;
	}

	count = 0;
	for(i = 0; i < 11; i++){
		for(j = 0; j < 11; j++){
			a[count] = b2[i] * b5[j];
			count++;
		}
	}

	bcount = 0;
	for(i = 0; i < count; i++){
		if(check(a[i]) == true){
			b[bcount] = a[i];
			bcount++;
		}
	}

	for(i = 0; i < bcount - 1; i++){
		for(j = i + 1; j < bcount; j++){
			if(b[i] > b[j]){
				tmp = b[i];
				b[i] = b[j];
				b[j] = tmp;
			}
		}
	}

	while(scanf("%lld%lld", &m, &n) == 2){
		x = 0;
		while(b[x] < m){
			x++;
		}

		result = x;
		while(b[result] <= n && b[result] > 0){
			result++;
		}
		result = result - x;

		printf("%d\n", result);
	}

	return 0;
}

