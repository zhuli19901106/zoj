#include <stdio.h>

int main()
{
	int s;
	int d;
	int count;

	while(1)
	{
		scanf("%d%d", &s, &d);
		if(s == 0 && d == 0)
		{
			break;
		}

		if(s * d % 60 == 0)
		{
			printf("Impossible\n");
		}
		else
		{
			count = 0;
			while(1)
			{
				s = ((d + 1) * s) % 60;
				count++;
				if(s == 0)
				{
					printf("%d\n", count);
					break;
				}
				else if(s != 0 && count > 999)
				{
					printf("Impossible\n");
					break;
				}
			}
		}
	}

	return 0;
}

