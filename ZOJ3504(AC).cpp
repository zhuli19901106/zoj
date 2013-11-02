#include <math.h>
#include <stdio.h>
#include <string.h>

int main()
{
	double xa[100];
	double ya[100];
	double xb[100];
	double yb[100];
	double za[100];
	double zb[100];
	double p;
	double pnorm;
	int count;
	char line[2000];
	int i;
	int len;
	int pos;

	while(1)
	{
		gets(line);
		len = strlen(line);
		count = 0;
		for(i = 0; i < len; i++)
		{
			if(line[i] == '(')
			{
				count++;
			}
		}

		if(count == 0)
		{
			break;
		}

		pos = 0;
		for(i = 0; i < count; i++)
		{
			while(line[pos] != '(')
			{
				pos++;
			}
			sscanf(line + pos, "(%lf,%lf)", &xa[i], &xb[i]);
			pos++;
		}

		gets(line);
		len = strlen(line);

		pos = 0;
		for(i = 0; i < count; i++)
		{
			while(line[pos] != '(')
			{
				pos++;
			}
			sscanf(line + pos, "(%lf,%lf)", &ya[i], &yb[i]);
			pos++;
		}

		gets(line);
		sscanf(line, "%lf", &p);

		for(i = 0; i < count; i++)
		{
			za[i] = xa[i] - ya[i];
			zb[i] = xb[i] - yb[i];
		}

		pnorm = 0;
		for(i = 0; i < count; i++)
		{
			pnorm = pnorm + pow(za[i] * za[i] + zb[i] * zb[i], 0.5 * p);
		}
		pnorm = pow(pnorm, 1.0 / p);

		printf("%lf\n", pnorm);
	}

	return 0;
}

