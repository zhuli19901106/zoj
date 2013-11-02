#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

void myswap(int &x, int &y)
{
	int t;
	
	t = x;
	x = y;
	y = t;
}

map<int, int> mm;
int p, q;
int maxres;

int solve(int x, int y, int z)
{
	int res;
	int i;
	map<int, int> ms;
	vector<int> vs;

	ms.clear();
	vs.clear();

	vs.push_back(x);
	vs.push_back(y);
	vs.push_back(z);
	vs.push_back(x + y);
	vs.push_back(y + z);
	vs.push_back(z + x);
	vs.push_back(x - y);
	vs.push_back(y - z);
	vs.push_back(z - x);
	vs.push_back(y - x);
	vs.push_back(z - y);
	vs.push_back(x - z);
	vs.push_back(- x - y - z);
	vs.push_back(- x - y + z);
	vs.push_back(- x + y - z);
	vs.push_back(- x + y + z);
	vs.push_back(+ x - y - z);
	vs.push_back(+ x - y + z);
	vs.push_back(+ x + y - z);
	vs.push_back(+ x + y + z);

	res = 0;
	for(i = 0; i < (int)vs.size(); ++i){
		if(vs[i] > 0 && ms.find(vs[i]) == ms.end()){
			ms[vs[i]] = 0;
			++res;
		}
	}

	ms.clear();
	vs.clear();

	return res;
}

int main()
{
	int t, ti;
	int res;
	int x, y, z;
	int x1, y1, z1;

	while(scanf("%d", &t) == 1){
		for(ti = 0; ti < t; ++ti){
			mm.clear();
			scanf("%d%d", &p, &q);
			maxres = 0;
			for(x1 = 1; x1 <= p - x1; ++x1){
				y1 = p - x1;
				z1 = q;
				x = x1;
				y = y1;
				z = z1;
				if(x > y){
					myswap(x, y);
				}
				if(x > z){
					myswap(x, z);
				}
				if(y > z){
					myswap(y, z);
				}
				if(mm.find(x * 101 * 101 + y * 101 + z) == mm.end()){
					mm[x * 101 * 101 + y * 101 + z] = 0;
					res = solve(x, y, z);
					if(res > maxres){
						maxres = res;
					}
				}
			}

			for(x1 = 1; x1 <= q - x1; ++x1){
				y1 = q - x1;
				z1 = p;
				x = x1;
				y = y1;
				z = z1;
				if(x > y){
					myswap(x, y);
				}
				if(x > z){
					myswap(x, z);
				}
				if(y > z){
					myswap(y, z);
				}
				if(mm.find(x * 101 * 101 + y * 101 + z) == mm.end()){
					mm[x * 101 * 101 + y * 101 + z] = 0;
					res = solve(x, y, z);
					if(res > maxres){
						maxres = res;
					}
				}
			}
			printf("%d\n", maxres);
			mm.clear();
		}
	}

	return 0;
}

