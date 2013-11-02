#include <stdio.h>
#include <string.h>

char getplain(const char ch, const char plain[], const char cipher[], int len)
{
	int i;

	for(i = 0; i < len; i++)
	{
		if(cipher[i] == ch)
		{
			return plain[i];
		}
	}

	return ch;
}

char getcipher(const char ch, const char plain[], const char cipher[], int len)
{
	int i;

	for(i = 0; i < len; i++)
	{
		if(plain[i] == ch)
		{
			return cipher[i];
		}
	}

	return ch;
}

int main()
{
	char plain[1000];
	char cipher[1000];
	char buffer[1000];
	int i;
	int len;
	int tablelen;

	/*while(1)*/
	{
		gets(plain);
		gets(cipher);
		tablelen = strlen(plain);
		puts(cipher);
		puts(plain);
		while(gets(buffer) != NULL)
		{
			len = strlen(buffer);
			if(len == 0)
			{
				break;
			}
			else
			{
				for(i = 0; i < len; i++)
				{
					printf("%c", getcipher(buffer[i], plain, cipher, tablelen));
				}
				printf("\n");
			}
		}
	}

	return 0;
}

