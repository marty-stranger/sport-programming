#include <stdio.h>
#include <string.h>

int main() {
	char s[1001];
	gets(s);

	int n = strlen(s);

	int i, j, pn = 0, p[1000];
	for (i = 2; i <= n; i++) {
		for (j = 0; j < pn; j++)
			if (i % p[j] == 0)
				break;

		if (j == pn)
			p[pn++] = i;
	}

	int c = 1;
	for (i = 0; i < pn; i++)
		if (2*p[i] > n)
			c++;

	int lc[200], m = -1, ml;
	memset(lc, 0, sizeof(lc));
	for (i = 0; i < n; i++) {
		lc[s[i]]++;
		if (lc[s[i]] > m) {
			m = lc[s[i]];
			ml = s[i];
		}
	}

	if (n - c <= m) {
		puts("YES");

		char ss[2000];
		memset(ss, 0, sizeof(ss));

		for (i = 0; i < pn; i++)
			if (2*p[i] <= n)
				for (j = p[i]; j <= n; j += p[i])
					if (ss[j-1] == 0) {
						ss[j-1] = ml;
						lc[ml]--;
					}

		char l = 'a';
		for (i = 0; i < n; i++)
			if (ss[i] == 0) {
				while (lc[l] == 0)
					l++;

				ss[i] = l;
				lc[l]--;
			}

		ss[n] = '\0';
		puts(ss);
	} else
		puts("NO");

	return 0;
}
