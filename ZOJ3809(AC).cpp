#include <cstdio>
#include <vector>
using namespace std;

int main()
{
	vector<int> v;
	int n;
	int i;
	int t, ti;
	int cc;

	scanf("%d", &t);
	for (ti = 0; ti < t; ++ti) {
		scanf("%d", &n);
		v.resize(n);
		for (i = 0; i < n; ++i) {
			scanf("%d", &v[i]);
		}
		cc = 0;
		for (i = 1; i < n - 1; ++i) {
			if (v[i] > v[i - 1] && v[i] > v[i + 1]) {
				++cc;
			}
		}
		printf("%d\n", cc);
		v.clear();
	}

	return 0;
}