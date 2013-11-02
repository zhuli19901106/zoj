#include <stdio.h>

int main()
{
	int w1;
	int l1;
	int w2;
	int l2;
	int w3;
	int l3;
	int w4;
	int l4;
	int sum;
	int dif;

	while(1)
	{
		scanf("%d%d%d%d%d%d", &w1, &l1, &w2, &l2, &w3, &l3);
		if(w1 == 0 && l1 == 0 && w2 == 0 && l2 == 0 && w3 == 0 && l3 == 0)
		{
			break;
		}

		sum = w1 + l1;
		dif = l1 + l2 + l3 - w1 - w2 - w3;
		w4 = (sum + dif) / 2;
		l4 = (sum - dif) / 2;

		printf("Anna's won-loss record is %d-%d.\n", w4, l4);
	}

	return 0;
}

