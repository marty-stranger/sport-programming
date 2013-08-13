#include <stdio.h>

const int mod = (int)1e9 + 7;

int sum(int a, int b) {
	int c = a + b;
	if (c > mod)
		c -= mod;
	return c;
}

int main() {
	int n, m, k; scanf("%d%d%d", &n, &m, &k);

	int c[1000][1000] = {0};
	c[0][0] = 1;
	for (int i = 1; i < n || i < m; i++) {
		c[i][0] = 1;
		for (int j = 1; j <= i; j++)
			c[i][j] = sum(c[i-1][j-1], c[i-1][j]);
	}

	int c1 = 2*k <= n-1 ? c[n-1][2*k] : 0;
	int c2 = 2*k <= m-1 ? c[m-1][2*k] : 0;

	printf("%d\n", 1ll*c1*c2 % mod);

	return 0;
}
