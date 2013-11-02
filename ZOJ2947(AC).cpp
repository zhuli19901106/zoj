#include <stdio.h>
#include <string.h>

int main()
{
	int i;
	int j;
	char buffer[1000];
	int len;
	char s1[100];
	char s2[100];
	int k;
	int n;
	int t;

	gets(buffer);
	sscanf(buffer, "%d", &t);
	for(i = 0; i < t; i++)
	{
		gets(buffer);
		sscanf(buffer, "%d", &n);
		gets(buffer);
		len = strlen(buffer);
		j = 0;
		k = 0;
		while(1)
		{
			s1[k] = buffer[j];
			k++;
			if(k == n)
			{
				break;
			}
			j++;
			while(buffer[j] != ' ')
			{
				j++;
			}
			while(buffer[j] == ' ')
			{
				j++;
			}
		}
		s1[k] = 0;

		gets(buffer);
		sscanf(buffer, "%d", &n);
		gets(buffer);
		len = strlen(buffer);
		j = 0;
		k = 0;
		while(1)
		{
			s2[k] = buffer[j];
			k++;
			if(k == n)
			{
				break;
			}
			j++;
			while(buffer[j] != ' ')
			{
				j++;
			}
			while(buffer[j] == ' ')
			{
				j++;
			}
		}
		s2[k] = 0;

		if(strcmp(s1, s2) == 0)
		{
			printf("SAME\n");
		}
		else
		{
			printf("DIFFERENT\n");
		}
	}

	return 0;
}

