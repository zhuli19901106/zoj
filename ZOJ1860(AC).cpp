#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
using namespace std;

typedef struct point{
	double x;
	double y;
}Point;

int n;
vector<Point> v;
Point p, d, g;

double dist(const Point p1, const Point p2)
{
	return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

int main()
{
	int i;
	double dg, dd;
	char s[1000];
	char *pstr;

	while(true){
		if(gets(s) == NULL){
			break;
		}
		sscanf(s, "%lf%lf%lf%lf", &g.x, &g.y, &d.x, &d.y);
		n = 0;
		v.clear();
		while((pstr = gets(s)) != NULL){
			if(!s[0]){
				break;
			}
			sscanf(s, "%lf%lf", &p.x, &p.y);
			v.push_back(p);
		}

		for(i = 0; i < (int)v.size(); ++i){
			dg = dist(g, v[i]);
			dd = dist(d, v[i]);
			if(dd > 2.0 * dg){
				printf("The gopher can escape through the hole at (%.3f,%.3f).\n", v[i].x, v[i].y);
				break;
			}
		}
		if(i == (int)v.size()){
			printf("The gopher cannot escape.\n");
		}

		if(pstr == NULL){
			break;
		}
	}

	return 0;
}

