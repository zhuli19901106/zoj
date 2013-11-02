#include <stdio.h>
#include <string.h>

int check(char str[])
{
	int i;
	int len;
	int modified;

	modified = 0;
	len = strlen(str);
	for(i = 0; i < len; i++)
	{
		if(str[i] == '1')
		{
			str[i] = '@';
			modified = 1;
		}
		else if(str[i] == '0')
		{
			str[i] = '%';
			modified = 1;
		}
		else if(str[i] == 'l')
		{
			str[i] = 'L';
			modified = 1;
		}
		else if(str[i] == 'O')
		{
			str[i] = 'o';
			modified = 1;
		}
	}

	return modified;
}

int main()
{
	int n;
	int i;
	char user[1000][11];
	char pass[1000][11];
	int modified[1000];
	int m;

	while(1)
	{
		scanf("%d", &n);
		if(n == 0)
		{
			break;
		}

		m = 0;
		for(i = 0; i < n; i++)
		{
			scanf("%s%s", user[i], pass[i]);
			if(check(pass[i]) != 0)
			{
				modified[m] = i;
				m++;
			}
		}

		if(m > 0)
		{
			printf("%d\n", m);
			for(i = 0; i < m; i++)
			{
				printf("%s %s\n", user[modified[i]], pass[modified[i]]);
			}
		}
		else if(m == 0)
		{
			printf("No account is modified.\n");
		}
	}

	return 0;
}

