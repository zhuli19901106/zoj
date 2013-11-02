#include <stdio.h>
#include <string.h>

int main()
{
	int i;
	int j;
	int n;
	char colors[1000][16];
	int count[1000];
	int colorcount;
	int maxindex;

	while(1)
	{
		gets(colors[0]);
		sscanf(colors[0], "%d", &n);

		if(n == 0)
		{
			break;
		}

		for(i = 0; i < n; i++)
		{
			count[i] = 0;
		}
		colorcount = 0;
		maxindex = 0;
		for(i = 0; i < n; i++)
		{
			gets(colors[colorcount]);
			for(j = 0; j < colorcount; j++)
			{
				if(strcmp(colors[colorcount], colors[j]) == 0)
				{
					count[j]++;
					if(count[j] > count[maxindex])
					{
						maxindex = j;
					}
					break;
				}
			}

			if(j == colorcount)
			{
				count[colorcount]++;
				colorcount++;

				if(count[colorcount - 1] > count[maxindex])
				{
					maxindex = colorcount - 1;
				}
			}
		}

		printf("%s\n", colors[maxindex]);
	}

	return 0;
}

