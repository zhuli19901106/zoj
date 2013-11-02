#include <stdio.h>
#include <string.h>

int main()
{
	char buffer[1000];
	char rest[1000];
	int i;
	int j;
	int countz;
	int counto;
	int countj;
	int count7;
	int len;

	while(gets(buffer) != NULL)
	{
		len = strlen(buffer);
		countz = counto = countj = count7 = 0;
		j = 0;
		for(i = 0; i < len; i++)
		{
			switch(buffer[i])
			{
			case 'Z':
				countz++;
				break;
			case 'O':
				counto++;
				break;
			case 'J':
				countj++;
				break;
			case '7':
				count7++;
				break;
			default:
				rest[j] = buffer[i];
				j++;
				break;
			}
		}
		rest[j] = 0;
		for(i = 0; i < countz; i++)
		{
			printf("%c", 'Z');
		}
		for(i = 0; i < counto; i++)
		{
			printf("%c", 'O');
		}
		for(i = 0; i < countj; i++)
		{
			printf("%c", 'J');
		}
		for(i = 0; i < count7; i++)
		{
			printf("%c", '7');
		}
		puts(rest);
	}

	return 0;
}

