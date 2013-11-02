#include <stdio.h>
#include <string.h>

int main()
{
	char correct[200];
	char wrong[200];
	char buffer[200];
	int i;
	int j;
	int n;
	int lenc;
	int lenw;
	int time;

	gets(buffer);
	sscanf(buffer, "%d", &n);
	for(i = 0; i < n; i++)
	{
		gets(buffer);
		sscanf(buffer, "%d", &time);
		gets(correct);
		gets(wrong);
		lenc = strlen(correct);
		lenw = strlen(wrong);
		for(j = 0; correct[j] != 0 && wrong[j] != 0; j++)
		{
			if(correct[j] != wrong[j])
			{
				break;
			}
		}

		if(correct[j] != 0 && wrong[j] != 0)
		{
			printf("%d\n", (lenw + lenc - 2 * j) * time);
		}
		else if(correct[j] == 0 && wrong[j] != 0)
		{
			printf("%d\n", (lenw - j) * time);
		}
		else if(correct[j] != 0 && wrong[j] == 0)
		{
			printf("%d\n", (lenc - j) * time);
		}
		else
		{
			printf("0\n");
		}
	}

	return 0;
}

