#include <cmath>
#include <cstdio>
using namespace std;

int main()
{
	int n, m;
	double s1, s2;
	double v1, v2;
	int i;
	int t, ti;
	int a1, a2;

	scanf("%d", &t);
	for (ti = 0; ti < t; ++ti) {
		scanf("%d%d", &n, &m);
		s1 = 0;
		for (i = 0; i < n - 1; ++i) {
			scanf("%lf", &v1);
			s1 += v1;
		}
		s1 /= n - 1;
		s2 = 0;
		for (i = 0; i < m; ++i) {
			scanf("%lf", &v2);
			s2 += v2;
		}
		s2 /= m;
		if (s1 == (int)s1) {
			a1 = s1 - 1;
		} else {
			a1 = s1;
		}
		if (s2 == (int)ceil(s2)) {
			a2 = s2 + 1;
		} else {
			a2 = (int)ceil(s2);
		}
		printf("%d %d\n", a2, a1);
	}

	return 0;
}