#include <cstdio>
#include <cstring>
using namespace std;

int read(char s[])
{
	int len, i;
	int d;
	int sum;

	len = strlen(s);
	d = 1;
	sum = 0;
	for (i = 0; i < len; ++i) {
		if (s[i] >= '2' && s[i] <= '9') {
			d = s[i] - '0';
		} else if (s[i] == 'm') {
			sum += d * 1000;
			d = 1;
		} else if (s[i] == 'c') {
			sum += d * 100;
			d = 1;
		} else if (s[i] == 'x') {
			sum += d * 10;
			d = 1;
		} else if (s[i] == 'i') {
			sum += d;
			d = 1;
		}
	}
	return sum;
}

void print(int n)
{
	int d[4];
	int i;
	char s[] = "ixcm";

	for (i = 0; i < 4; ++i) {
		d[i] = n % 10;
		n /= 10;
	}
	for (i = 3; i >= 0; --i) {
		if (d[i] == 1) {
			putchar(s[i]);
		} else if (d[i] > 1) {
			printf("%d%c", d[i], s[i]);
		}
	}
}

int main()
{
	int d;
	char s1[100], s2[100];
	int t, ti;

	scanf("%d", &t);
	for (ti = 0; ti < t; ++ti) {
		scanf("%s%s", s1, s2);
		d = 0;
		d += read(s1);
		d += read(s2);
		print(d);
		printf("\n");
	}

	return 0;
}