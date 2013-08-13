#include <stdio.h>
#include <string.h>

int n, bn = 0, bu[1000000], bv[1000000], c[1000], cc = 0;
char g[1000][1000], b[1000], bb[1000];

void dfs(int u, int w) {
	b[u] = 1;
	bb[u] = 1;
	c[u] = cc;

	int v;
	for (v = 0; v < n; v++)
		if (g[u][v]) {
			if (bb[v] && v != w) {
				bu[bn] = u; bv[bn] = v; bn++;
			}

			if (!b[v])
				dfs(v, u);
		}

	bb[u] = 0;
}

int main() {
	scanf("%d", &n);

	int i;
	memset(g, 0, sizeof(g));
	for (i = 0; i < n-1; i++) {
		int u, v; scanf("%d%d", &u, &v); u--; v--;
		g[u][v] = g[v][u] = 1;
	}

	memset(b, 0, sizeof(b));
	memset(bb, 0, sizeof(bb));
	int u;
	for (u = 0; u < n; u++)
		if (!b[u]) {
			dfs(u, -1);
			cc++;
		}

	/* printf("cc = %d\n", cc);
	for (u = 0; u < n; u++)
		printf("%d ", c[u]);
	putchar('\n'); */

	for (i = 0; i < bn; i++) {
		g[bu[i]][bv[i]] = 0;
		g[bv[i]][bu[i]] = 0;
	}

	memset(b, 0, sizeof(b));

	for (u = 0; u < n; u++)
		if (c[u] == 0)
			break;

	int cn = 0, cu[1000000], cv[1000000];

	for (i = 1; i < cc; i++) {
		int v;
		for (v = 0; v < n; v++)
			if (c[v] == i)
				break;

		cu[cn] = u; cv[cn] = v; cn++;
	}

	// printf("%d\n", bn);
	printf("%d\n", cn);
	for (i = 0; i < bn; i++)
		printf("%d %d %d %d\n", bu[i]+1, bv[i]+1, cu[i]+1, cv[i]+1);

	return 0;
}
