#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int main()
{
	int t, ti;
	int n;
	vector<double> v;
	int i;
	char s[10];
	double sum, b;

	scanf("%d", &t);
	for (ti = 0; ti < t; ++ti) {
		scanf("%d%s", &n, s);
		v.resize(n);
		for (i = 0; i < n; ++i) {
			scanf("%lf", &v[i]);
		}
		if (strcmp(s, "bit") == 0) {
			b = 2;
		} else if (strcmp(s, "nat") == 0) {
			b = exp(1.0);
		} else if (strcmp(s, "dit") == 0) {
			b = 10;
		}
		sum = 0;
		for (i = 0; i < n; ++i) {
			if (v[i] == 0) {
				continue;
			}
			v[i] /= 100.0;
			sum += v[i] * log(v[i]) / log(b);
		}
		sum = -sum;
		printf("%.12f\n", sum);
		v.clear();
	}

	return 0;
}