#include <stdio.h>
#include <string.h>

int main()
{
	int i;
	int j;
	int n;
	int len;
	int ni;
	char buffer[1000];

	gets(buffer);
	sscanf(buffer, "%d", &n);
	for(ni = 0; ni < n; ni++)
	{
		gets(buffer);
		len = strlen(buffer);

		i = 0;
		j = i + 1;
		while(i < len)
		{
			while(buffer[i] == buffer[j])
			{
				j++;
			}
			if(j - i > 1)
			{
				printf("%d%c", j - i, buffer[i]);
				i = j;
				j = i + 1;
			}
			else if(j - i == 1)
			{
				printf("%c", buffer[i]);
				i = j;
				j = i + 1;
			}
		}

		printf("\n");
	}

	return 0;
}

