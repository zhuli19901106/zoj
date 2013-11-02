#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

int inbound(int x, int y, int left, int right, int bottom, int top)
{
	//return (x >= left && x < right) && (y >= bottom && y <= top);
	return 1;
}

int main()
{
	int t, ti;

	int x;
	int y;
	int a[34][34];
	int i, j;
	char s[1000];

	gets(s);
	sscanf(s, "%d", &t);
	for(ti = 1; ti <= t; ti++){
		for(i = 0; i < 34; i++){
			for(j = 0; j < 34; j++){
				a[i][j] = 0;
			}
		}

		gets(s);
		sscanf(s, "%d%d", &x, &y);
		gets(s);
		for(i = 0; s[i] != '.'; i++){
			switch(s[i]){
			case 'W':
				if(inbound(x - 1, y, 0, 31, 0, 31)){
					a[x - 1][y] = 1;
				}
				x--;
				break;
			case 'E':
				if(inbound(x, y - 1, 0, 31, 0, 31)){
					a[x][y - 1] = 1;
				}
				x++;
				break;
			case 'N':
				if(inbound(x, y, 0, 31, 0, 31)){
					a[x][y] = 1;
				}
				y++;
				break;
			case 'S':
				if(inbound(x - 1, y - 1, 0, 31, 0, 31)){
					a[x - 1][y - 1] = 1;
				}
				y--;
				break;
			}
		}

		printf("Bitmap #%d\n", ti);
		for(j = 31; j >= 0; j--){
			for(i = 0; i <= 31; i++){
				if(a[i][j] == 0){
					printf(".");
				}else if(a[i][j] == 1){
					printf("X");
				}
			}
			printf("\n");
		}
		
		printf("\n");
	}

	return 0;
}

