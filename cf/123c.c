#include <stdio.h>
#include <string.h>

char s[200];
long long c[200][400];

long long count(int n, int d) {
	if (n == 0)
		return d == 0;

	if (c[n][d] == -1) {
		long long cc = 0;
		if (s[n-1] != ')' && d > 0)
			cc += count(n-1, d-1);
		if (s[n-1] != '(')
			cc += count(n-1, d+1);

		const long long inf = 1000000000000000000;
		if (cc > inf)
			cc = inf;

		// printf("i = %d j = %d -> %d\n", n, d, cc);
		c[n][d] = cc;
	}

	return c[n][d];
}

int main() {
	int n, m;
       	long long k;
	// scanf("%d%d%lld", &n, &m, &k);
	scanf("%d%d%I64d", &n, &m, &k);

	int i, j, p[200];
	memset(p, -1, sizeof(p));
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++) {
			int pp;
			scanf("%d", &pp);
			pp--;

			if (p[i+j] == -1 || pp < p[i+j])
				p[i+j] = pp;
		}

	memset(s, '?', sizeof(s));
	s[m+n-1] = '\0';

	for (i = 0; i < m+n-1; i++) {
		int mi = -1; 
		for (j = 0; j < m+n-1; j++)
			if (p[j] != -1)
				if (mi == -1 || p[j] < p[mi])
					mi = j;
		// printf("mi = %d\n", mi);
		p[mi] = -1;

		s[mi] = '(';

		// printf("s = %s\n", s);

		memset(c, -1, sizeof(c));

		long long c = count(m+n-1, 0);
		// printf("c = %lld\n", c);
		if (k > c) {
			k -= c;
			s[mi] = ')';
		}
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++)
			putchar(s[i+j]);
		putchar('\n');
	}

	return 0;
}
