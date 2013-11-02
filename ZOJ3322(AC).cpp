#include <stdio.h>
#include <string.h>

int main()
{
	int y1;
	int m1;
	int d1;
	int y2;
	int m2;
	int d2;
	char buffer1[1000];
	char buffer2[1000];
	int ti;
	int t;
	int result;

	scanf("%d", &t);
	for(ti = 0; ti < t; ti++)
	{
		scanf("%d%d%d%d%d%d", &y1, &m1, &d1, &y2, &m2, &d2);
		buffer1[0] = 0;
		buffer2[0] = 0;

		sprintf(buffer1, "%04d%02d%02d", y1, m1, d1);
		sprintf(buffer2, "%04d%02d%02d", y2, m2, d2);

		result = strcmp(buffer1, buffer2);

		if(result > 0)
		{
			printf("cpcs\n");
		}
		else if(result == 0)
		{
			printf("same\n");
		}
		else
		{
			printf("javaman\n");
		}
	}

	return 0;
}

