#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

int main()
{
	int t;
	int ti;
	int y;
	char p1[10][20] = {
		"Jia",
		"Yi",
		"Bing",
		"Ding",
		"Wu",
		"Ji",
		"Geng",
		"Xin",
		"Ren",
		"Gui",
	};
	char p2[12][20] = {
		"zi",
		"chou",
		"yin",
		"mao",
		"chen",
		"si",
		"wu",
		"wei",
		"shen",
		"you",
		"xu",
		"hai"
	};
	int i1;
	int i2;
	int diff;

	scanf("%d", &t);
	for(ti = 0; ti < t; ti++)
	{
		scanf("%d", &y);
		if(y < 0)
		{
			y++;
		}
		diff = y - 1911;
		if(diff > 0)
		{
			i1 = (7 + diff % 10) % 10;
			i2 = (11 + diff % 12) % 12;

			printf("%s%s\n", p1[i1], p2[i2]);
		}
		else
		{
			diff = -diff;

			i1 = (7 + 10 - diff % 10) % 10;
			i2 = (11 + 12 - diff % 12) % 12;

			printf("%s%s\n", p1[i1], p2[i2]);
		}
	}

	return 0;
}

