#include <stdio.h>
#include <string.h>

int main()
{
	char buffer[100];
	char result[100];
	int i;
	int j;
	int n;

	while(1)
	{
		if(gets(buffer) == NULL)
		{
			break;
		}

		if(sscanf(buffer, "%d", &n) != 1)
		{
			break;
		}

		for(i = 0; i < 8; i++)
		{
			result[i] = 0;
		}

		for(i = 0; i < 2 * n - 1; i++)
		{
			gets(buffer);
			for(j = 0; j < 7; j++)
			{
				result[j] = result[j] ^ buffer[j];
			}
		}

		puts(result);
	}

	return 0;
}

