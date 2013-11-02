#include <stdio.h>
#include <string.h>

int main()
{
	int i;
	int j;
	int t;
	int len;
	int sum;
	int base;
	int value;
	char buffer[1000];
	char digits[200];


	gets(buffer);
	sscanf(buffer, "%d", &t);

	for(i = 0; i < t; i++)
	{
		gets(buffer);
		while(1)
		{
			gets(buffer);
			if(strcmp(buffer, "0") == 0)
			{
				break;
			}
			else
			{
				sscanf(buffer, "%d %s", &base, digits);
			}

			sum = 0;
			value = 0;
			len = strlen(digits);
			for(j = 0; j < len; j++)
			{
				sum = sum + digits[j] - '0';
				value = value * base;
				value = value + digits[j] - '0';
			}

			if(value % sum == 0)
			{
				printf("yes\n");
			}
			else
			{
				printf("no\n");
			}
		}
		if(i != t - 1)
		{
			puts("");
		}
	}

	return 0;
}

