#include <stdio.h>
#include <string.h>

int main()
{
	char protocol[10], host[61], str[61], path[61], port[11];
	int i,n,k = 0,m;

	scanf("%d",&n);
	while (getchar() != '\n');

	while (n -- > 0)
	{
		i = 0;
		k++;
		gets(str);
		printf("URL #%d\n", k);

		for (i = 0,m = 0;str[i] != ':'; i++)
		{
			protocol[m ++] = str[i];
		}
		protocol[m] = '\0';
		i += 3;

		for (m = 0; str[i] != '\0' && str[i] != ':' && str[i] != '/'; i++)
		{
			host[m ++] = str[i];
		}
		host[m] = '\0';

		if (str[i] == '\0')
		{
			printf("Protocol = %s\nHost     = %s\nPort     = <default>\nPath     = <default>\n\n",protocol,host);
		}
		else if (str[i] == '/')
		{
			for (i++,m = 0;str[i] != '\0'; i++)
			{
				path[m ++] = str[i];
			}
			path[m] = '\0';

			printf("Protocol = %s\nHost     = %s\nPort     = <default>\nPath     = %s\n\n",protocol,host,path);
		}
		else
		{
			for (i++,m = 0;str[i] != '\0'&& str[i] != '/'; i++)
			{
				port[m ++] = str[i];
			}
			port[m] = '\0';

			if (str[i] == '\0')
			{
				printf("Protocol = %s\nHost     = %s\nPort     = %s\nPath     = <default>\n\n",protocol,host,port);
			}
			else
			{
				for (i++,m = 0;str[i] != '\0'; i++)
				{
					path[m ++] = str[i];
				}
				path[m] = '\0';

				printf("Protocol = %s\nHost     = %s\nPort     = %s\nPath     = %s\n\n",protocol,host,port,path);

			}
		}
	}
	return 0;

}

