#include <stdio.h>
#include <string.h>

int max(int a, int b)
{
	return (a > b ? a : b);
}

int chartoint(const char ch)
{
	if(ch >= '0' && ch <= '9')
	{
		return ch - '0';
	}
	else if(ch >= 'a' && ch <= 'j')
	{
		return ch - 'a' + 10;
	}
	else
	{
		return -1;
	}
}

char inttochar(const int i)
{
	if(i >= 0 && i <= 9)
	{
		return i + '0';
	}
	else if(i >= 10 && i <= 19)
	{
		return i - 10 + 'a';
	}
	else
	{
		return 0;
	}
}

void getdigits(const char str[], int a[])
{
	int i;
	int len;

	len = strlen(str);
	for(i = len - 1; i >= 0; i--)
	{
		a[len - 1 - i] = chartoint(str[i]);
	}
}

void getstring(const int a[], char str[], int n)
{
	int i;
	int j;
	int start;

	for(i = n; i >= 0; i--)
	{
		if(a[i] != 0)
		{
			break;
		}
	}
	if(i == -1)
	{
		strcpy(str, "0");
		return;
	}

	start = 0;
	j = 0;
	while(i >= 0)
	{
		if(start == 0)
		{
			if(a[i] != 0)
			{
				start = 1;
				str[j] = inttochar(a[i]);
				j++;
			}
		}
		else
		{
			str[j] = inttochar(a[i]);
			j++;
		}
		i--;
	}
	str[j] = 0;
}

void add(int a[], int b[], int c[], int n)
{
	int i;

	for(i = 0; i < n; i++)
	{
		c[i] = a[i] + b[i];
	}

	for(i = 0; i < n; i++)
	{
		if(c[i] < 0)
		{
			c[i] = c[i] + 20;
			c[i + 1]--;
		}
		else if(c[i] > 19)
		{
			c[i] = c[i] - 20;
			c[i + 1]++;
		}
	}
}

int main()
{
	char stra[200];
	char strb[200];
	char strc[200];
	int i;
	int lena;
	int lenb;
	int digita[200];
	int digitb[200];
	int digitc[200];

	while(1)
	{
		for(i = 0; i < 200; i++)
		{
			stra[i] = 0;
			strb[i] = 0;
			strc[i] = 0;
			digita[i] = 0;
			digitb[i] = 0;
			digitc[i] = 0;
		}

		if(scanf("%s", stra) != 1)
		{
			break;
		}

		scanf("%s", strb);
		lena = strlen(stra);
		lenb = strlen(strb);
		getdigits(stra, digita);
		getdigits(strb, digitb);
		add(digita, digitb, digitc, 105);
		getstring(digitc, strc, max(lena, lenb) + 1);

		puts(strc);
	}

	return 0;
}

