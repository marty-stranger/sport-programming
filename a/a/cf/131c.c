#include <stdio.h>
#include <string.h>

int main() {
	int n, m, t;
	scanf("%d%d%d", &n, &m, &t);

	long long c[31][31];
	memset(c, 0, sizeof(c));
	c[0][0] = 1;

	int i, j;
	for (i = 1; i <= 30; i++) {
		c[i][0] = 1;
		for (j = 1; j <= 30; j++)
			c[i][j] = c[i-1][j-1] + c[i-1][j];
	}

	long long r = 0;
	for (i = 4; i <= t-1; i++)
		if (i <= n && t-i <= m)
			r += c[n][i] * c[m][t-i];

	printf("%I64d", r);

	return 0;
}
