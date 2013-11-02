#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;
#define NORTH 0
#define EAST  1
#define SOUTH 2
#define WEST  3

int main()
{
	char maze[62][62];
	int sr, sc;
	int r, c;
	char s[1000];
	int heading;
	int rr, rc;
	int i, j;
	bool game_over;
	
	while(true){
		if(scanf("%d%d", &sr, &sc) == EOF){
			break;
		}
		getchar();

		for(r = 0; r <= sr + 1; ++r){
			for(c = 0; c <= sc + 1; ++c){
				maze[r][c] = '*';
			}
		}
		
		for(r = 1; r <= sr; ++r){
			gets(s);
			for(c = 1; c <= sc; ++c){
				maze[r][c] = s[c - 1];
			}
		}
		
		scanf("%d%d", &rr, &rc);
		getchar();
		heading = NORTH;
		
		game_over = false;
		while(true){
			if(game_over){
				break;
			}else{
				gets(s);
				i = 0;
				while(!game_over && s[i] != 0){
					switch(s[i]){
						case 'R':
							heading = (heading + 1) % 4;
							break;
						case 'L':
							heading = (heading + 3) % 4;
							break;
						case 'F':
							switch(heading){
								case NORTH:
									if(maze[rr - 1][rc] == ' '){
										--rr;
									}
									break;
								case EAST:
									if(maze[rr][rc + 1] == ' '){
										++rc;
									}
									break;
								case SOUTH:
									if(maze[rr + 1][rc] == ' '){
										++rr;
									}
									break;
								case WEST:
									if(maze[rr][rc - 1] == ' '){
										--rc;
									}
									break;
							}
							break;
						case 'Q':
							printf("%d %d ", rr, rc);
							switch(heading){
								case NORTH:
									printf("N\n");
									break;
								case EAST:
									printf("E\n");
									break;
								case SOUTH:
									printf("S\n");
									break;
								case WEST:
									printf("W\n");
									break;
							}
							game_over = true;
							break;
					}
					i++;
				}
			}
		}
	}
	
	return 0;
}

