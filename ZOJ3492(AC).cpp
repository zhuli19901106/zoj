#include <stdio.h>
#include <string.h>

int main()
{
	int t;
	int i;
	int j;
	int n;
	int i1;
	int i2;
	char name1[25];
	char name[105][25];

	while(1)
	{
		if(scanf("%d", &t) != 1)
		{
			break;
		}

		for(i = 0; i < t; i++)
		{
			scanf("%d", &n);
			scanf("%s", name1);

			for(j = 0; j < n; j++)
			{
				scanf("%s", name[j]);
			}

			for(j = 0; j < n; j++)
			{
				if(strcmp(name1, name[j]) == 0)
				{
					i1 = j;
					break;
				}
			}

			i2 = (i1 + n / 2) % n;
			printf("%s\n", name[i2]);
		}
	}

	return 0;
}

