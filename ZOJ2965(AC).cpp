#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>

bool cocacola(const int &n)
{
	int i;
	char s[20];

	if(n % 7 == 0){
		return true;
	}else{
		sprintf(s, "%d", n);
		for(i = 0; s[i] != 0; i++){
			if(s[i] == '7'){
				return true;
			}
		}

		return false;
	}
}

int main()
{
	int left;
	int right;
	int n;
	int t;
	int a[1000];
	int count;

	count = 0;
	n = 1;
	while(count < 1000){
		if(cocacola(n)){
			a[count] = n;
			count++;
		}
		n++;
	}

	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		left = 0;
		right = left + 1;
		while(true){
			if(right - left >= n){
				break;
			}

			if(a[right] - a[right - 1] != 1){
				left = right;
				right = left + 1;
			}else{
				right++;
			}
		}

		printf("%d\n", a[left]);
	}

	return 0;
}

