#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>

struct st
{
	int l;
	int w;
};

int comp(const void *a, const void *b)
{
	const struct st *sa, *sb;
	
	sa = (const struct st *)a;
	sb = (const struct st *)b;
	
	if(sa->l == sb->l){
		return sa->w > sb->w;
	}else{
		return sa->l > sb->l;
	}
}

int main()
{
	int case_no, case_count;
	int count, n, res;
	int i, j;
	int visited[10000];
	struct st a[10000];
	
	while(true){
		if(scanf("%d", &case_count) != 1){
			break;
		}
		for(case_no = 0; case_no < case_count; ++case_no){
			scanf("%d", &n);
			for(i = 0; i < n; ++i){
				scanf("%d%d", &a[i].l, &a[i].w);
			}
			qsort(a, n, sizeof(struct st), comp);
			count = 0;
			memset(visited, 0, 10000 * sizeof(int));
			res = 0;
			while(count < n){
				i = -1;
				j = 0;
				while(true){
					if(j >= n){
						break;
					}else if(visited[j]){
						++j;
					}else if(count == 0 || (a[i].l <= a[j].l && a[i].w <= a[j].w)){
						visited[j] = 1;
						i = j;
						++j;
						++count;
					}else{
						++j;
					}
				}
				++res;
			}
			
			printf("%d\n", res);
		}
	}
	
	return 0;
}
