#include <stdio.h>
#include <string.h>

const int inf = 1000000000;
char s[2501];
int n, c[2500][2500];

int g(int l, int r) {
	int m, cc;

	if (l == r + 1)
		return 0;

	if (c[l][r] != -1)
		return c[l][r];

	if ('A' <= s[l] && s[l] <= 'Z')
		return inf;

	if ('a' <= s[l] && s[l] <= 'z') {
		c[l][r] = inf;
		for (m = l + 1; m <= r; m++)
			if (s[m] - 'A' == s[l] - 'a') {
				cc = g(l + 1, m - 1) + g(m + 1, r) + 1;
				if (cc < c[l][r])
					c[l][r] = cc;
			} else if (s[m] == '*') {
				cc = g(l + 1, m) + g(m, r) + 1;
				if (cc < c[l][r])
					c[l][r] = cc;
			}
	} else if (s[l] == '*') {
		c[l][r] = g(l + 1, r);
		for (m = l + 1; m <= r; m++)
			if ('A' <= s[m] && s[m] <= 'Z') {
				cc = g(l, m - 1) + g(m + 1, r) + 1;
				if (cc < c[l][r])
					c[l][r] = cc;
			}

	}

	printf("l = %d r = %d c = %d\n", l, r, c[l][r]);

	return c[l][r];
} 

int main() {
	int i, j, cc;

	gets(s); n = strlen(s);

	memset(c, -1, sizeof(c));

	cc = g(0, n - 1);

	if (cc == inf)
		puts("-1");
	else
		printf("%d\n", cc);

	return 0;
}
