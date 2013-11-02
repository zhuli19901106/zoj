#include <stdio.h>

int main()
{
	int i;
	int n;
	int seq[101];
	int occupy[101];
	int count;
	int top;

	while(1)
	{
		scanf("%d", &n);
		if(n == 0)
		{
			break;
		}

		for(i = 1; i <= n; i++)
		{
			scanf("%d", &seq[i]);
			occupy[i] = 0;
		}

		top = n + 1;
		count = 0;
		for(i = 1; i <= n; i++)
		{
			if(top == 1)
			{
				count++;
			}
			else
			{
				if(seq[i] < top)
				{
					top = seq[i];
					occupy[top] = 1;
				}
				else
				{
					top--;
					occupy[top] = 1;
				}
			}
		}

		printf("%d\n", count);
	}

	return 0;
}

