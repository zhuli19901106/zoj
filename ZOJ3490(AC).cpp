#ifndef _ZOJ_3490_CPP_
#define _ZOJ_3490_CPP_

#ifndef _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
#include <cstring>
using namespace std;

int getdata(char str[], int ds[], int bs[], int pos[])
{
	int i;
	int len;
	int dc;

	len = strlen(str);
	dc = 0;
	for(i = len - 1; i >= 0; i--)
	{
		if(str[i] >= '0' && str[i] <= '9')
		{
			ds[dc] = str[i] - '0';
			bs[dc] = 10;
			pos[dc] = i;
			dc++;
		}
		else if(str[i] >= 'a' && str[i] <= 'z')
		{
			ds[dc] = str[i] - 'a';
			bs[dc] = 26;
			pos[dc] = i;
			dc++;
		}
		else if(str[i] >= 'A' && str[i] <= 'Z')
		{
			ds[dc] = str[i] - 'A';
			bs[dc] = 26;
			pos[dc] = i;
			dc++;
		}
	}

	return dc;
}

int main()
{
	char str[300];
	char buffer[300];
	int n;
	int i;
	int j;
	int k;
	int ds[300];
	int bs[300];
	int pos[300];
	int dc;
	int t;
	int ti;

	scanf("%d", &t);
	for(ti = 0; ti < t; ti++)
	{
		scanf("%s%d", str, &n);
		dc = getdata(str, ds, bs, pos);

		for(i = 0; i < n; i++)
		{
			if(dc > 0)
			{
				for(j = 0; j < dc; j++)
				{
					if(ds[j] < bs[j] - 1)
					{
						break;
					}
				}

				if(j == dc)
				{
					for(k = 0; k < dc; k++)
					{
						ds[k] = 0;
						str[pos[k]] = str[pos[k]] - bs[k] + 1;
					}

					switch(str[pos[dc - 1]])
					{
					case '0':
						strcpy(buffer, str);
						buffer[pos[dc - 1]] = '\0';
						strcat(buffer, "1");
						strcat(buffer, str + pos[dc - 1]);
						strcpy(str, buffer);
						break;
					case 'a':
						strcpy(buffer, str);
						buffer[pos[dc - 1]] = '\0';
						strcat(buffer, "a");
						strcat(buffer, str + pos[dc - 1]);
						strcpy(str, buffer);
						break;
					case 'A':
						strcpy(buffer, str);
						buffer[pos[dc - 1]] = '\0';
						strcat(buffer, "A");
						strcat(buffer, str + pos[dc - 1]);
						strcpy(str, buffer);
						break;
					}

					dc = getdata(str, ds, bs, pos);
				}
				else
				{
					for(k = 0; k < j; k++)
					{
						ds[k] = 0;
						str[pos[k]] = str[pos[k]] - bs[k] + 1;
					}
					ds[j]++;
					str[pos[j]]++;
				}
			}
			else if(dc == 0)
			{
				int len;

				len = strlen(str);
				str[len - 1]++;
				if(str[len - 1] >= '0' && str[len - 1] <= '9')
				{
					dc = getdata(str, ds, bs, pos);
				}
				else if(str[len - 1] >= 'a' && str[len - 1] <= 'z')
				{
					dc = getdata(str, ds, bs, pos);
				}
				else if(str[len - 1] >= 'A' && str[len - 1] <= 'Z')
				{
					dc = getdata(str, ds, bs, pos);
				}
			}
			printf("%s\n", str);
		}
		printf("\n");
	}

	return 0;
}

#endif
#endif

