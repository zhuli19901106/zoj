#include <stdio.h>
#include <string.h>

int main()
{
	char plain[1000];
	char key[500];
	int keylen;
	int cipherlen;
	int it;
	int cht;
	int order[50];
	char cipher[500];
	int ni;
	int i;
	int j;
	int k;
	int n;
	int rem;
	int row;

	gets(plain);
	sscanf(plain, "%d", &n);
	for(ni = 0; ni < n; ni++)
	{
		gets(key);
		keylen = strlen(key);
		gets(cipher);
		cipherlen = strlen(cipher);

		for(i = 0; i < keylen; i++)
		{
			order[i] = i;
		}

		for(i = 0; i < keylen - 1; i++)
		{
			for(j = i + 1; j < keylen; j++)
			{
				if(key[i] > key[j])
				{
					it = order[i];
					order[i] = order[j];
					order[j] = it;

					cht = key[i];
					key[i] = key[j];
					key[j] = cht;
				}
			}
		}

		if(cipherlen % keylen == 0)
		{
			row = cipherlen / keylen;
			for(i = 0; i < cipherlen; i++)
			{
				plain[(i % row) * keylen + order[i / row]] = cipher[i];
			}
			plain[cipherlen] = 0;
		}
		else
		{
			row = cipherlen / keylen;
			rem = cipherlen % keylen;
			k = 0;
			for(i = 0; i < keylen; i++)
			{
				if(order[i] >= rem)
				{
					for(j = 0; j < row; j++)
					{
						plain[j * keylen + order[i]] = cipher[k];
						k++;
					}
				}
				else
				{
					for(j = 0; j < row + 1; j++)
					{
						plain[j * keylen + order[i]] = cipher[k];
						k++;
					}
				}
			}
			plain[cipherlen] = 0;
		}

		for(i = 0; i < cipherlen; i++)
		{
			if(plain[i] >= 'A' && plain[i] <= 'Z')
			{
				plain[i] = plain[i] - 'A' + 'a';
			}
		}

		puts(plain);
	}

	return 0;
}

