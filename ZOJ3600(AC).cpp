#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

double fare(double dist, double flag_down, double price_plus_3, double price_plus_10)
{
	double cost;
	
	//dist = ceil(dist);
	if(dist <= 0){
		return 0;
	}else if(dist > 0 && dist <= 3){
		return flag_down;
	}else if(dist > 3 && dist <= 10){
		return flag_down + price_plus_3 * (dist - 3);
	}else{
		return flag_down + price_plus_3 * (10 - 3) + price_plus_10 * (dist - 10);
	}
	
	return cost;
}

int main()
{
	double cost1, cost2;
	double dist, wtime;
	int case_count, case_no;
	
	while(true){
		if(scanf("%d", &case_count) != 1){
			break;
		}
		for(case_no = 0; case_no < case_count; ++case_no){
			scanf("%lf%lf", &dist, &wtime);
			cost1 = fare(dist, 10, 2, 3) + 2.0 * wtime / 5.0 + 1.0;
			cost2 = fare(dist, 11, 2.5, 3.75) + 2.5 * wtime / 4.0;
			cost1 = int(cost1 + 0.5);
			cost2 = int(cost2 + 0.5);
			
			printf("%d\n", (int)(cost2 - cost1));
		}
	}
	
	return 0;
}

