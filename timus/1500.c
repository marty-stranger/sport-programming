#include <stdio.h>
#include <string.h>

int n, mask, g[30][30], b[30];

int dfs(int u) {
	int v;

	b[u] = 1;

	if (u == 1)
		return 1;

	for (v = 0; v < n; v++)
		if (!b[v] && g[u][v] & mask)
			if (dfs(v))
				return 1;

	return 0;
}

int count(int a) {
	int k = 0;

	while (a != 0) {
		k += a % 2;
		a /= 2;
	}

	return k;
}

int main() {
	int m, k, i, u, v, c, mc, mmask;

	scanf("%d%d%d", &k, &n, &m);

	memset(g, 0, sizeof(g));
	for (i = 0; i < m; i++) {
		scanf("%d%d%d", &u, &v, &c);
		g[u][v] |= 1 << c;
		g[v][u] |= 1 << c;
	}

	mc = 1000000000;
	for (mask = 0; mask < 1 << k; mask++) {
		memset(b, 0, sizeof(b));
		if (dfs(0)) {
			c = count(mask);
			if (c < mc) {
				mc = c;
				mmask = mask;
			}
		}
	}

	printf("%d\n", mc);
	for (i = 0; i < k; i++)
		if (mmask & 1 << i)
			printf("%d ", i);

	return 0;
}
	
