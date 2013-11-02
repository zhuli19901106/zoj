#include <stdio.h>
#include <string.h>

int main()
{
	int n;
	int i;
	int j;
	int p;
	int k;
	int count;
	int nk;
	char keywords[101][25];
	char words[30];

	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%s", keywords[i]);
	}
	scanf("%d", &k);
	for(i = 0; i < k; i++)
	{
		count = 0;
		scanf("%d", &nk);
		for(j = 0; j < nk; j++)
		{
			scanf("%s", words);
			for(p = 0; p < n; p++)
			{
				if(strcmp(words, keywords[p]) == 0)
				{
					count++;
					break;
				}
			}
		}

		printf("%d\n", count);
	}

	return 0;
}

