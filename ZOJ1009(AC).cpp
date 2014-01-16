#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	const int MAXN = 27;
	const int MAXLEN = 1005;
	char s[MAXLEN];
	int a[3][MAXN];
	int off[3];
	int tmp[2];
	int m1[MAXN];
	int m2[MAXN];
	int msg[MAXLEN];
	int res[MAXLEN];
	int i, j, k;
	int m, n;
	int slen;
	int case_count;

	case_count = 0;
	while (scanf("%d", &m) == 1 && m) {
		if (case_count > 0) {
			printf("\n");
		}
		++case_count;

		for (i = 0; i < 3; ++i) {
			scanf("%s", s);
			for (j = 0; j < m; ++j) {
				a[i][j] = ((s[j] + m) - ('A' + j)) % m;
			}
		}

		scanf("%d", &n);
		printf("Enigma %d:\n", case_count);
		for (i = 0; i < n; ++i) {
			scanf("%s", s);
			for (j = 0; j < 3; ++j) {
				off[j] = 0;
			}
			slen = strlen(s);
			for (j = 0; j < slen; ++j) {
				msg[j] = s[j] - 'A';
			}
			for (j = 0; j < slen; ++j) {
				for (k = 0; k < m; ++k) {
					m1[k] = (k + a[2][(k + (m - j / (m * m) % m)) % m]) % m;
					m2[m1[k]] = k;
				}
				tmp[0] = m2[msg[j]];
				for (k = 0; k < m; ++k) {
					m1[k] = (k + a[1][(k + (m - j / m % m)) % m]) % m;
					m2[m1[k]] = k;
				}
				tmp[1] = m2[tmp[0]];
				for (k = 0; k < m; ++k) {
					m1[k] = (k + a[0][(k + (m - j % m)) % m]) % m;
					m2[m1[k]] = k;
				}
				res[j] = m2[tmp[1]];
				putchar('a' + res[j]);
			}
			putchar('\n');
		}
	}


	return 0;
}