#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	double H;
	double h;
	double D;
	double L;
	double sum;
	int t;

	//sum = D * (1 + (H - h) / (L - H)) + L;
	//dsum = D * (h - H) / ((L - H) * (L - H)) + 1;

	scanf("%d", &t);
	while(t--){
		scanf("%lf%lf%lf", &H, &h, &D);
		L = H - sqrt(D * (H - h));
		if(L < 0){
			L = 0;
		}

		if(L > h){
			L = h;
		}

		sum = D * (h - L) / (H - L) + L;
		printf("%0.3f\n", sum);
	}

	return 0;
}

