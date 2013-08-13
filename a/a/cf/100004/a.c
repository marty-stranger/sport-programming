#include <stdio.h>
#include <string.h>

int g[100001], lv[200002], lw[200002], ln[200002], td[100001], b[100001];

int dfs(int u, int d) {
	int li;

	td[u] = d;

	for (li = g[u]; li != -1; li = ln[li]) {
		int v = lv[li], w = lw[li];
		if (td[v] == -1)
			dfs(v, d + w);
	}
}

int min(int a, int b) {
	return a < b ? a : b;
}

int main() {
	int n;
	scanf("%d", &n);

	int u, d[100001];
	for (u = 0; u <= n; u++)
		scanf("%d", &d[u]);


	int i, li, s = 0;
	memset(g, -1, sizeof(g));
	for (i = 0; i < n; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);

		lv[li] = v; ln[li] = g[u]; lw[li] = w, g[u] = li; li++;
		lv[li] = u; ln[li] = g[v]; lw[li] = w, g[v] = li; li++;
		s += 2*w;
	}

	memset(td, -1, sizeof(td));
	dfs(0, 0);

	int m = 2000000000;
	for (u = 0; u <= n; u++)
		m = min(m, s - td[u] + d[u]);

	printf("%d\n", m);

	return 0;
}
