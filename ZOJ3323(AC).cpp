#include <stdio.h>
#include <string.h>

int main()
{
	char buffer[1000];
	int i;
	int j;
	int n;
	int len;

	gets(buffer);
	sscanf(buffer, "%d", &n);
	for(i = 0; i < n; i++)
	{
		gets(buffer);
		len = strlen(buffer);
		for(j = 0; j < len; j++)
		{
			if(buffer[j] < '0' || buffer[j] > '9')
			{
				printf("%c", buffer[j]);
			}
		}
		printf("\n");
	}

	return 0;
}

