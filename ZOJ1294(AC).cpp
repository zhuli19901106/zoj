#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

int main()
{
	int p, s;
	int d;
	int cc;

	cc = 0;
	while(true)
	{
		scanf("%d%d", &p, &s);
		if(p == 0)
		{
			break;
		}
		else
		{
			cc++;
			d = s - p;
		}

		printf("Hole #%d\n", cc);
		if(s == 1)
		{
			printf("Hole-in-one.\n");
		}
		else if(d == -3)
		{
			printf("Double Eagle.\n");
		}
		else if(d == -2)
		{
			printf("Eagle.\n");
		}
		else if(d == -1)
		{
			printf("Birdie.\n");
		}
		else if(d == 0)
		{
			printf("Par.\n");
		}
		else if(d == 1)
		{
			printf("Bogey.\n");
		}
		else
		{
			printf("Double Bogey.\n");
		}
		printf("\n");
	}

	return 0;
}

