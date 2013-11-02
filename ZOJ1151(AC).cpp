#include <stdio.h>
#include <string.h>

void reverse(char a[], int left, int right)
{
	int i;
	int j;
	int len;
	char ch;

	len = strlen(a);
	if(left < 0 || right >= len)
	{
		return;
	}

	i = left;
	j = right;
	while(i < j)
	{
		ch = a[i];
		a[i] = a[j];
		a[j] = ch;
		i++;
		j--;
	}
}

int main()
{
	char buffer[1000];
	int i;
	int j;
	int n;
	int t;
	int left;
	int right;

	gets(buffer);
	sscanf(buffer, "%d", &n);
	for(i = 0; i < n; i++)
	{
		gets(buffer);
		gets(buffer);
		sscanf(buffer, "%d", &t);
		for(j = 0; j < t; j++)
		{
			gets(buffer);
			left = 0;
			right = 0;
			while(buffer[left] != '\0')
			{
				while(buffer[left] == ' ')
				{
					left++;
				}
				while(buffer[right] != ' ' && buffer[right] != '\0')
				{
					right++;
				}
				right--;
				reverse(buffer, left, right);
				left = right + 1;
				right = left + 1;
			}

			puts(buffer);
		}
		if(i != n - 1)
		{
			puts("");
		}
	}

	return 0;
}

