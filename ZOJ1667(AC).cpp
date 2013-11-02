#include <stdio.h>
#include <string.h>

int main()
{
	int i;
	int n;
	char cmd[1000];
	int top;
	int bottom;
	int north;
	int south;
	int west;
	int east;
	int tmp;

	while(1)
	{
		top = 1;
		north = 2;
		west = 3;
		bottom = 6;
		south = 5;
		east = 4;
		gets(cmd);
		sscanf(cmd, "%d", &n);
		if(n == 0)
		{
			break;
		}

		for(i = 0; i < n; i++)
		{
			gets(cmd);
			if(strcmp(cmd, "north") == 0)
			{
				tmp = top;
				top = south;
				south = bottom;
				bottom = north;
				north = tmp;
			}
			else if(strcmp(cmd, "east") == 0)
			{
				tmp = top;
				top = west;
				west = bottom;
				bottom = east;
				east = tmp;
			}
			else if(strcmp(cmd, "south") == 0)
			{
				tmp = top;
				top = north;
				north = bottom;
				bottom = south;
				south = tmp;
			}
			else if(strcmp(cmd, "west") == 0)
			{
				tmp = top;
				top = east;
				east = bottom;
				bottom = west;
				west = tmp;
			}
		}

		printf("%d\n", top);
	}

	return 0;
}

