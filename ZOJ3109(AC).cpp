#include <stdio.h>
#include <string.h>
#define LEFT 1
#define RIGHT 2
#define UP 3
#define DOWN 4

int main()
{
	char buffer[1000];
	char result[1000];
	char mat[21][21];
	int i;
	int j;
	int k;
	int dir;
	int row;
	int col;
	int len;
	int leftbound;
	int rightbound;
	int upbound;
	int downbound;

	while(1)
	{
		gets(buffer);
		sscanf(buffer, "%d %d", &row, &col);
		if(row == 0 && col == 0)
		{
			break;
		}

		gets(buffer);

		len = strlen(buffer);
		for(i = 0; i < len; i++)
		{
			buffer[i] = buffer[i] - 7;
		}

		for(i = 0; i < len; i++)
		{
			mat[i / col][i % col] = buffer[i];
			if(i % col == col - 1)
			{
				mat[i / col][col] = 0;
			}
		}

		k = 0;
		i = 0;
		j = 0;
		leftbound = 0;
		rightbound = col - 1;
		upbound = 0;
		downbound = row - 1;
		dir = RIGHT;

		while(k < len)
		{
			switch(dir)
			{
			case LEFT:
				result[k] = mat[i][j];
				k++;
				if(j == leftbound)
				{
					dir = UP;
					downbound--;
					i--;
				}
				else
				{
					j--;
				}
				break;
			case RIGHT:
				result[k] = mat[i][j];
				k++;
				if(j == rightbound)
				{
					dir = DOWN;
					upbound++;
					i++;
				}
				else
				{
					j++;
				}
				break;
			case UP:
				result[k] = mat[i][j];
				k++;
				if(i == upbound)
				{
					dir = RIGHT;
					leftbound++;
					j++;
				}
				else
				{
					i--;
				}
				break;
			case DOWN:
				result[k] = mat[i][j];
				k++;
				if(i == downbound)
				{
					dir = LEFT;
					rightbound--;
					j--;
				}
				else
				{
					i++;
				}
				break;
			}
		}
		result[k] = 0;

		puts(result);
	}

	return 0;
}

