#include <stdio.h>
#include <string.h>

int main()
{
	int n;
	int i;
	int j;
	int k;
	int len;
	char buffer[1000];

	while(1)
	{
		if(scanf("%d", &n) != 1)
		{
			break;
		}

		for(i = 1; i <= n; i++)
		{
			scanf("%d", &k);
			scanf("%s", buffer);
			len = strlen(buffer);

			printf("%d ", i);
			for(j = 0; j < len; j++)
			{
				if(j == k - 1)
				{
					continue;
				}
				else
				{
					printf("%c", buffer[j]);
				}
			}
			printf("\n");
		}
	}

	return 0;
}

