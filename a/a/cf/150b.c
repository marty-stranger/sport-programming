#include <stdio.h>
#include <string.h>

int n;
char g[2000][2000], b[2000];

void dfs(int u) {
	int v;

	b[u] = 1;
	for (v = 0; v < n; v++)
		if (g[u][v] && !b[v])
			dfs(v);
}

int main() {
	int m, k;

	scanf("%d%d%d", &n, &m, &k);

	memset(g, 0, sizeof(g));

	int i;
	for (i = 0; i + k <= n; i++) {
		int l = i, r = i+k-1;
		while (l <= r) {
			g[l][r] = g[r][l] = 1;
			l++; r--;
		}
	}

	/* int j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			printf("%d", g[i][j]);
		puts("");
	} */

	int cc = 0;
	memset(b, 0, sizeof(b));
	for (i = 0; i < n; i++)
		if (!b[i]) {
			dfs(i);
			cc++;
		}

	// printf("cc = %d\n", cc);

	int c = 1;
	for (i = 0; i < cc; i++)
		c = (1LL *c * m) % 1000000007;

	printf("%d\n", c);

	return 0;
}
