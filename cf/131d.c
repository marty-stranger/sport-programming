#include <stdio.h>
#include <string.h>

int n, cu, cv;
char g[3000][3000], b[3000], c[3000];
int p[3000];

void dfs(int u, int w) {
	b[u] = 1;

	int v;
	for (v = 0; v < n; v++)
		if (g[u][v] && v != w)
			if (b[v] == 0) {
				p[v] = u;
				dfs(v, u);
			} else if (b[v] == 1)
				cu = u, cv = v;

	b[u] = 2;
}

int main() {
	scanf("%d", &n);

	memset(g, 0, sizeof(g));
	int i;
	for (i = 0; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		u--; v--;

		g[u][v] = g[v][u] = 1;
	}

	memset(b, 0, sizeof(b));
	memset(c, 0, sizeof(c));

	dfs(0, -1);

	int v = cu;
	while (v != cv) {
		c[v] = 1;
		v = p[v];
	}
	c[v] = 1;

	int u, d[3000], qs = 0, qe = 0, q[3000];
	for (u = 0; u < n; u++)
		if (c[u]) {
			d[u] = 0;
			q[qe++] = u;
		} else
			d[u] = -1;

	while (qs < qe) {
		int u = q[qs++];

		int v;
		for (v = 0; v < n; v++)
			if (g[u][v] && d[v] == -1) {
				d[v] = d[u] + 1;
				q[qe++] = v;
			}
	}

	for (u = 0; u < n; u++)
		printf("%d ", d[u]);
	putchar('\n');


	return 0;
}
