#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

int main()
{
	int a[1000];
	int b[1000];
	int sca;
	int scb;
	int n;
	int i;
	int casecount;

	casecount = 0;
	while(true)
	{
		if(scanf("%d", &n) != 1)
		{
			break;
		}
		else
		{
			if(n == 0)
			{
				break;
			}

			casecount++;
			if(casecount > 1)
			{
				printf("\n");
			}
		}


		for(i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
		}

		for(i = 0; i < n; i++)
		{
			scanf("%d", &b[i]);
		}

		sca = 0;
		scb = 0;

		for(i = 0; i < n; i++)
		{
			if(a[i] == 1 && b[i] == 2)
			{
				sca += 6;
			}
			else if(b[i] == 1 && a[i] == 2)
			{
				scb += 6;
			}
			else if(a[i] - b[i] > 1)
			{
				sca += a[i];
			}
			else if(a[i] - b[i] == 1)
			{
				scb += a[i] + b[i];
			}
			else if(b[i] - a[i] > 1)
			{
				scb += b[i];
			}
			else if(b[i] - a[i] == 1)
			{
				sca += a[i] + b[i];
			}
		}

		printf("A has %d points. B has %d points.\n", sca, scb);
	}

	return 0;
}

