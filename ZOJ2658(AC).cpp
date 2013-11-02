#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int comparator(const void *a, const void *b)
{
	return *(int *)a > *(int *)b;
}

int main()
{
	int i;
	int counta[26];
	int countb[26];
	int lena;
	int lenb;
	char buffera[1000];
	char bufferb[1000];

	while(1)
	{
		if(gets(buffera) == NULL)
		{
			break;
		}
		else if(buffera[0] == 0)
		{
			continue;
		}

		gets(bufferb);
		lena = strlen(buffera);
		lenb = strlen(bufferb);
		memset(counta, 0, 26 * sizeof(int));
		memset(countb, 0, 26 * sizeof(int));
		for(i = 0; i < lena; i++)
		{
			counta[buffera[i] - 'A']++;
			countb[bufferb[i] - 'A']++;
		}
		qsort(counta, 26, sizeof(int), comparator);
		qsort(countb, 26, sizeof(int), comparator);
		for(i = 0; i < 26; i++)
		{
			if(counta[i] != countb[i])
			{
				break;
			}
		}

		if(i == 26)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}

	return 0;
}

