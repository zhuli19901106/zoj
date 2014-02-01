#include <cmath>
#include <cstdio>
using namespace std;

int main()
{
	double vs;
	double c;
	double r;
	double w;
	int times;
	
	scanf("%lf%lf%lf%d", &vs, &r, &c, &times);
	double r2 = r * r;
	double vsr = vs * r;
	double c2 = c * c;
	for (int i = 0; i < times; i++) {
		scanf("%lf", &w);
		printf("%.3f\n", vsr / sqrt(r2 + 1.0 / (w * w * c2)));
	}
	
	return 0;
}