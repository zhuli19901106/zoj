#include <stdio.h>
#include <string.h>

int main()
{
	int tabs;
	int spaces;
	char buffer[1000];
	int len;
	int i;
	int t;
	int ti;

	gets(buffer);
	sscanf(buffer, "%d", &t);
	for(ti = 0; ti < t; ti++)
	{
		tabs = 0;
		spaces = 0;
		while(1)
		{
			gets(buffer);
			if(strcmp(buffer, "##") == 0)
			{
				break;
			}

			len = strlen(buffer);
			for(i = len - 1; i >= 0; i--)
			{
				if(buffer[i] == ' ')
				{
					spaces++;
				}
				else if(buffer[i] == '\t')
				{
					tabs++;
					spaces = spaces + 4;
				}
				else
				{
					break;
				}
			}

			i--;
			while(i >= 0)
			{
				if(buffer[i] == '\t')
				{
					tabs++;
				}
				i--;
			}
		}

		printf("%d tab(s) replaced\n", tabs);
		printf("%d trailing space(s) removed\n", spaces);
	}

	return 0;
}

