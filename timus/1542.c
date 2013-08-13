#include <stdio.h>
#include <string.h>

int p[15][100000], f[100000], c[15][256], ct[256], cc[100001], cct[100001], pp[100000], lp[100000];
char s[100000][16], ss[16];

int main() {
	int n, m, i, d, k, j, l, r, mm;

	memset(s, 0, sizeof(s));
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%s %d", s[i], &f[i]);

	memset(c, 0, sizeof(c));
	for (d = 0; d < 15; d++) {
		for (i = 0; i < n; i++)
			c[d][s[i][d]]++;
		for (i = 1; i < 256; i++)
			c[d][i] += c[d][i - 1];
	}

	memset(cc, 0, sizeof(cc));
	for (i = 0; i < n; i++)
		cc[f[i]]++;
	for (i = 100000 - 1; i >= 0; i--)
		cc[i] += cc[i + 1];

	for (i = 0; i < n; i++)
		lp[i] = i;

	for (k = 15 - 1; k >= 0; k--) {
		memcpy(p[k], lp, sizeof(lp));
		if (k + 1 < 15) {
			memcpy(ct, c[k + 1], sizeof(ct));
			for (i = n - 1; i >= 0; i--)
				pp[--ct[s[p[k][i]][k + 1]]] = p[k][i];
			memcpy(p[k], pp, sizeof(pp));
		}

		memcpy(lp, p[k], sizeof(lp));

		memcpy(cct, cc, sizeof(cc));
		for (i = n - 1; i >= 0; i--)
			pp[--cct[f[p[k][i]]]] = p[k][i];
		memcpy(p[k], pp, sizeof(pp));
			
		for (d = k; d >= 0; d--) {
			memcpy(ct, c[d], sizeof(ct));
			for (i = n - 1; i >= 0; i--)
				pp[--ct[s[p[k][i]][d]]] = p[k][i];
			memcpy(p[k], pp, sizeof(pp));
		}

	}

	scanf("%d", &m);
	for (i = 0; i < m; i++) {
		if (i != 0)
			putchar('\n');

		scanf("%s", ss);
		
		k = strlen(ss);

		l = 0; r = n - 1;
		while (l < r) {
			mm = (l + r) / 2;
			if (strncmp(ss, s[p[k - 1][mm]], k) <= 0)
				r = mm;
			else
				l = mm + 1;
		}

		j = 0;
		while (j < 10 && l + j < n && !strncmp(ss, s[p[k - 1][l + j]], k)) {
			printf("%s\n", s[p[k - 1][l + j]]);
			j++;
		}
	}

	return 0;
}
