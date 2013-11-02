#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	int j;
	int s, p, y;
	int a, b, c;
	bool found;
	
	while(true){
		if(scanf("%d%d%d%d", &s, &p, &y, &j) != 4){
			break;
		}		
		
		found = false;
		for(a = s + p; !found && a <= 12 + j; ++a){
			for(b = a - (s + 1); !found && b <= a - s; ++b){
				c = 12 + j - a - b;
				if(
					(a - b == s || a - b == s + 1)
					&&
					(b - c == p || b - c == p + 1)
					&&
					(a - c == y || a - c == y + 1)
				){
					found = true;
					break;
				}
			}
			if(found){
				break;
			}
		}

		if(found){
			printf("%d %d %d\n", a, b, c);
		}
	}
	
	return 0;
}

