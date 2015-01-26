#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
using namespace std;

typedef struct point{
	int x;
	int y;
}Point;
queue<Point> q;
int a[10][10];
int b[10][10];
bool suc;
const int d[4][2] = {
	{-1, 0}, {+1, 0}, {0, -1}, {0, +1}
};

inline bool inbound(const int x, const int y)
{
	return (x >= 1 && x <= 9) && (y >= 1 && y <= 9);
}

bool check_horizontal()
{
	int i, j, k;
	int c[10];
	Point pp, p1;
	int sc;

	for(i = 1; !suc && i <= 9; ++i){
		for(j = 1; !suc && j <= 5; ++j){
			memset(c, 0, 10 * sizeof(int));
			for(k = 0; k < 5; ++k){
				++c[a[i][j + k]];
			}

			if(c[0] == 1){
				for(k = 1; k <= 9; ++k){
					if(c[k] == 4){
						break;
					}
				}

				if(k <= 9){
					sc = k;
				}else{
					sc = -1;
				}

				if(sc != -1){
					for(k = 0; k < 5; ++k){
						if(!a[i][j + k]){
							pp.x = i;
							pp.y = j + k;
							break;
						}
					}
					memset(b, 0, 10 * 10 * sizeof(int));
					for(k = 0; k < 5; ++k){
						b[i][j + k] = 1;
					}
					while(!q.empty()){
						q.pop();
					}
					q.push(pp);
					while(!q.empty()){
						pp = q.front();
						q.pop();
						for(k = 0; k < 4; ++k){
							if(inbound(pp.x + d[k][0], pp.y + d[k][1])){
								p1.x = pp.x + d[k][0];
								p1.y = pp.y + d[k][1];
								if(a[p1.x][p1.y] == 0 && !b[p1.x][p1.y]){
									b[p1.x][p1.y] = 1;
									q.push(p1);
								}else if(a[p1.x][p1.y] == sc && !b[p1.x][p1.y]){
									while(!q.empty()){
										q.pop();
									}
									return true;
								}
							}
						}
					}
				}
			}
			//inside of the loop
		}
	}

	return false;
}

bool check_vertical()
{
	int i, j, k;
	int c[10];
	Point pp, p1;
	int sc;

	for(i = 1; !suc && i <= 9; ++i){
		for(j = 1; !suc && j <= 5; ++j){
			memset(c, 0, 10 * sizeof(int));
			for(k = 0; k < 5; ++k){
				++c[a[j + k][i]];
			}

			if(c[0] == 1){
				for(k = 1; k <= 9; ++k){
					if(c[k] == 4){
						break;
					}
				}

				if(k <= 9){
					sc = k;
				}else{
					sc = -1;
				}

				if(sc != -1){
					for(k = 0; k < 5; ++k){
						if(!a[j + k][i]){
							pp.x = j + k;
							pp.y = i;
							break;
						}
					}
					memset(b, 0, 10 * 10 * sizeof(int));
					for(k = 0; k < 5; ++k){
						b[j + k][i] = 1;
					}
					while(!q.empty()){
						q.pop();
					}
					q.push(pp);
					while(!q.empty()){
						pp = q.front();
						q.pop();
						for(k = 0; k < 4; ++k){
							if(inbound(pp.x + d[k][0], pp.y + d[k][1])){
								p1.x = pp.x + d[k][0];
								p1.y = pp.y + d[k][1];
								if(a[p1.x][p1.y] == 0 && !b[p1.x][p1.y]){
									b[p1.x][p1.y] = 1;
									q.push(p1);
								}else if(a[p1.x][p1.y] == sc && !b[p1.x][p1.y]){
									while(!q.empty()){
										q.pop();
									}
									return true;
								}
							}
						}
					}
				}
			}
			//inside of the loop
		}
	}

	return false;
}

bool check_diagonal()
{
	int i, j, k;
	int c[10];
	Point pp, p1;
	int sc;

	for(i = 1; !suc && i <= 5; ++i){
		for(j = 1; !suc && j <= 5; ++j){
			memset(c, 0, 10 * sizeof(int));
			for(k = 0; k < 5; ++k){
				++c[a[i + k][j + k]];
			}

			if(c[0] == 1){
				for(k = 1; k <= 9; ++k){
					if(c[k] == 4){
						break;
					}
				}

				if(k <= 9){
					sc = k;
				}else{
					sc = -1;
				}

				if(sc != -1){
					for(k = 0; k < 5; ++k){
						if(!a[i + k][j + k]){
							pp.x = i + k;
							pp.y = j + k;
							break;
						}
					}
					memset(b, 0, 10 * 10 * sizeof(int));
					for(k = 0; k < 5; ++k){
						b[i + k][j + k] = 1;
					}
					while(!q.empty()){
						q.pop();
					}
					q.push(pp);
					while(!q.empty()){
						pp = q.front();
						q.pop();
						for(k = 0; k < 4; ++k){
							if(inbound(pp.x + d[k][0], pp.y + d[k][1])){
								p1.x = pp.x + d[k][0];
								p1.y = pp.y + d[k][1];
								if(a[p1.x][p1.y] == 0 && !b[p1.x][p1.y]){
									b[p1.x][p1.y] = 1;
									q.push(p1);
								}else if(a[p1.x][p1.y] == sc && !b[p1.x][p1.y]){
									while(!q.empty()){
										q.pop();
									}
									return true;
								}
							}
						}
					}
				}
			}
			//inside of the loop
		}
	}

	return false;
}

bool check_anti_diagonal()
{
	int i, j, k;
	int c[10];
	Point pp, p1;
	int sc;

	for(i = 1; !suc && i <= 5; ++i){
		for(j = 5; !suc && j <= 9; ++j){
			memset(c, 0, 10 * sizeof(int));
			for(k = 0; k < 5; ++k){
				++c[a[i + k][j - k]];
			}

			if(c[0] == 1){
				for(k = 1; k <= 9; ++k){
					if(c[k] == 4){
						break;
					}
				}

				if(k <= 9){
					sc = k;
				}else{
					sc = -1;
				}

				if(sc != -1){
					for(k = 0; k < 5; ++k){
						if(!a[i + k][j - k]){
							pp.x = i + k;
							pp.y = j - k;
							break;
						}
					}
					memset(b, 0, 10 * 10 * sizeof(int));
					for(k = 0; k < 5; ++k){
						b[i + k][j - k] = 1;
					}
					while(!q.empty()){
						q.pop();
					}
					q.push(pp);
					while(!q.empty()){
						pp = q.front();
						q.pop();
						for(k = 0; k < 4; ++k){
							if(inbound(pp.x + d[k][0], pp.y + d[k][1])){
								p1.x = pp.x + d[k][0];
								p1.y = pp.y + d[k][1];
								if(a[p1.x][p1.y] == 0 && !b[p1.x][p1.y]){
									b[p1.x][p1.y] = 1;
									q.push(p1);
								}else if(a[p1.x][p1.y] == sc && !b[p1.x][p1.y]){
									while(!q.empty()){
										q.pop();
									}
									return true;
								}
							}
						}
					}
				}
			}
			//inside of the loop
		}
	}

	return false;
}

int main()
{
	int t, ti;
	int i, j;

	while(scanf("%d", &t) == 1){
		for(ti = 0; ti < t; ++ti){
			memset(a, 0, 10 * 10 * sizeof(int));
			for(i = 1; i <= 9; ++i){
				for(j = 1; j <= 9; ++j){
					scanf("%d", &a[i][j]);
				}
			}

			suc = false;
			if(!suc){
				suc = check_horizontal();
			}
			if(!suc){
				suc = check_vertical();
			}
			if(!suc){
				suc = check_diagonal();
			}
			if(!suc){
				suc = check_anti_diagonal();
			}
			if(suc){
				printf("Yes\n");
			}else{
				printf("No\n");
			}
		}
	}

	return 0;
}
