#include <stdio.h>

int main()
{
	int a[200];
	int b[200];
	int n;
	int ni;
	int t;
	int ti;
	int isqueue;
	int isstack;

	scanf("%d", &t);
	for(ti = 0; ti < t; ti++)
	{
		scanf("%d", &n);
		for(ni = 0; ni < n; ni++)
		{
			scanf("%d", &a[ni]);
		}

		for(ni = 0; ni < n; ni++)
		{
			scanf("%d", &b[ni]);
		}

		isqueue = 1;
		for(ni = 0; ni < n; ni++)
		{
			if(a[ni] != b[ni])
			{
				isqueue = 0;
				break;
			}
		}

		isstack = 1;
		for(ni = 0; ni < n; ni++)
		{
			if(a[ni] != b[n - 1 - ni])
			{
				isstack = 0;
				break;
			}
		}

		if(isstack == 0 && isqueue == 0)
		{
			printf("neither\n");
		}
		else if(isstack == 0 && isqueue == 1)
		{
			printf("queue\n");
		}
		else if(isstack == 1 && isqueue == 0)
		{
			printf("stack\n");
		}
		else
		{
			printf("both\n");
		}
	}

	return 0;
}

