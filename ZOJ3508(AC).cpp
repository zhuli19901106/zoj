#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <vector>
using namespace std;

struct node{
	int min;
	int max;
};

struct comp{
	bool operator()(const struct node &a, const node &b)
	{
		if(a.max == b.max){
			return a.min > b.min;
		}else{
			return a.max > b.max;
		}
	}
};

int main()
{
	int n, m;
	int i;
	int mc;
	priority_queue<struct node, vector<struct node>, comp> pq;
	struct node sn;
	vector<int> v;
	int w;
	vector<int>::iterator vit;
	
	while(true){
		v.clear();
		while(!pq.empty()){
			pq.pop();
		}

		if(scanf("%d%d", &n, &m) != 2){
			break;
		}
		for(i = 0; i < n; ++i){
			scanf("%d%d", &(sn.min), &(sn.max));
			pq.push(sn);
		}
		for(i = 0; i < m; ++i){
			scanf("%d", &w);
			v.push_back(w);
		}
		sort(v.begin(), v.end());
		mc = 0;
		for(i = 0; i < n; ++i){
			sn = pq.top();
			pq.pop();
			for(vit = v.begin(); vit != v.end(); ++vit){
				if((*vit) >= sn.min && (*vit) <= sn.max){
					++mc;
					v.erase(vit);
					break;
				}
			}
		}
		printf("%d\n", mc);
	}
	
	return 0;
}
