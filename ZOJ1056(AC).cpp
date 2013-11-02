#include <stdio.h>
#define LEN 20
#define WEST 1
#define EAST 2
#define NORTH 3
#define SOUTH 4

#define SUCCESS 0
#define OUT 1
#define COLLISION 2

int checkbump(int x[], int y[], int len, int headi)
{
	int i;

	for(i = 0; i < len; i++)
	{
		if(i == headi)
		{
			continue;
		}
		else
		{
			if(x[i] == x[headi] && y[i] == y[headi])
			{
				return 1;
			}
		}
	}

	return 0;
}

int main()
{
	char buffer[1000];
	int n;
	int i;
	int x[LEN];
	int y[LEN];
	int headi;
	int result;
	int dir;
	const int left = 1;
	const int top = 1;
	const int bottom = 50;
	const int right = 50;

	while(1)
	{
		for(i = 0; i < LEN; i++)
		{
			x[i] = 30 - i;
			y[i] = 25;
		}
		dir = EAST;
		headi = 0;
		result = SUCCESS;

		gets(buffer);
		sscanf(buffer, "%d", &n);
		if(n == 0)
		{
			break;
		}

		gets(buffer);
		for(i = 0; result == SUCCESS && i < n; i++)
		{
			switch(buffer[i])
			{
			case 'W':
				if(dir == EAST)
				{
					result = COLLISION;
				}
				else
				{
					dir = WEST;
					x[(headi + LEN - 1) % LEN] = x[headi] - 1;
					y[(headi + LEN - 1) % LEN] = y[headi];
					headi = (headi + LEN - 1) % LEN;
					if(x[headi] < left)
					{
						result = OUT;
					}
					else if(checkbump(x, y, LEN, headi) == 1)
					{
						result = COLLISION;
					}
				}
				break;
			case 'E':
				if(dir == WEST)
				{
					result = COLLISION;
				}
				else
				{
					dir = EAST;
					x[(headi + LEN - 1) % LEN] = x[headi] + 1;
					y[(headi + LEN - 1) % LEN] = y[headi];
					headi = (headi + LEN - 1) % LEN;
					if(x[headi] > right)
					{
						result = OUT;
					}
					else if(checkbump(x, y, LEN, headi) == 1)
					{
						result = COLLISION;
					}
				}
				break;
			case 'N':
				if(dir == SOUTH)
				{
					result = COLLISION;
				}
				else
				{
					dir = NORTH;
					x[(headi + LEN - 1) % LEN] = x[headi];
					y[(headi + LEN - 1) % LEN] = y[headi] - 1;
					headi = (headi + LEN - 1) % LEN;
					if(y[headi] < top)
					{
						result = OUT;
					}
					else if(checkbump(x, y, LEN, headi) == 1)
					{
						result = COLLISION;
					}
				}
				break;
			case 'S':
				if(dir == NORTH)
				{
					result = COLLISION;
				}
				else
				{
					dir = SOUTH;
					x[(headi + LEN - 1) % LEN] = x[headi];
					y[(headi + LEN - 1) % LEN] = y[headi] + 1;
					headi = (headi + LEN - 1) % LEN;
					if(y[headi] > bottom)
					{
						result = OUT;
					}
					else if(checkbump(x, y, LEN, headi) == 1)
					{
						result = COLLISION;
					}
				}
				break;
			}
		}

		switch(result)
		{
		case SUCCESS:
			printf("The worm successfully made all %d moves.\n", n);
			break;
		case OUT:
			printf("The worm ran off the board on move %d.\n", i);
			break;
		case COLLISION:
			printf("The worm ran into itself on move %d.\n", i);
			break;
		}
	}

	return 0;
}

