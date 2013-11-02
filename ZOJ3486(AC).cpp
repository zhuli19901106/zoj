#include <stdio.h>

int main()
{
	int n;
	int t;
	int i;
	int j;
	int k;
	int freq[1005];
	int id[1005];
	int count;
	int maxfreq;
	int maxid;

	while(1)
	{
		if(scanf("%d", &t) != 1)
		{
			break;
		}

		for(i = 0; i < t; i++)
		{
			scanf("%d", &n);
			count = 0;
			maxfreq = -1;
			for(j = 0; j < n; j++)
			{
				freq[j] = 0;
			}

			for(j = 0; j < n; j++)
			{
				scanf("%d", &id[count]);
				if(j == 0)
				{
					maxfreq = 1;
					maxid = id[count];
					freq[count] = 1;
					count++;
				}
				else if(j > 0)
				{
					for(k = 0; k < count; k++)
					{
						if(id[k] == id[count])
						{
							freq[k]++;
							if(freq[k] > maxfreq)
							{
								maxfreq = freq[k];
								maxid = id[k];
							}
							else if(freq[k] == maxfreq)
							{
								if(id[k] > maxid)
								{
									maxid = id[k];
								}
							}
							break;
						}
					}

					if(k == count)
					{
						freq[count] = 1;
						if(freq[count] > maxfreq)
						{
							maxid = id[count];
							maxfreq = freq[count];
						}
						else if(freq[count] == maxfreq)
						{
							if(id[count] > maxid)
							{
								maxid = id[count];
							}
						}
						count++;
					}
				}
			}

			printf("%d\n", maxid);
		}
	}

	return 0;
}

