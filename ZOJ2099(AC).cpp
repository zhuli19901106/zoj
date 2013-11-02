#include <cstdio>
using namespace std;

int main()
{
	int minx;
	int miny;
	int maxx;
	int maxy;
	int count;
	int x;
	int y;

	count = 0;
	while(1)
	{
		if(scanf("%d%d", &x, &y) != 2)
		{
			break;
		}

		if(x == 0 && y == 0 && count == 0)
		{
			break;
		}
		else if(x == 0 && y == 0)
		{
			printf("%d %d %d %d\n", minx, miny, maxx, maxy);
			count = 0;
		}
		else
		{
			if(count == 0)
			{
				minx = x;
				miny = y;
				maxx = x;
				maxy = y;
			}
			else
			{
				if(x < minx)
				{
					minx = x;
				}
				if(y < miny)
				{
					miny = y;
				}
				if(x > maxx)
				{
					maxx = x;
				}
				if(y > maxy)
				{
					maxy = y;
				}
			}
			count++;
		}
	}

	return 0;
}

