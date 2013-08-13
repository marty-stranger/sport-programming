#include <stdio.h>
#include <string.h>

int g[100000], l[200000], lw[200000], ln[200000], b[100000], mm;

void dfs(int u, int d) {
	b[u] = 1;

	if (d > mm)
		mm = d;

	int i;
	for (i = g[u]; i != -1; i = ln[i]) {
		int v = l[i], w = lw[i];

		if (!b[v])
			dfs(v, d + w);
	}
}

int main() {
	int n; scanf("%d", &n);

	memset(g, -1, sizeof(g));
	int i, li = 0, deg[100000];
	memset(deg, 0, sizeof(deg));
	long long s = 0;
	for (i = 0; i < n-1; i++) {
		int u, v, w; scanf("%d%d%d", &u, &v, &w); u--; v--;

		l[li] = v; lw[li] = w, ln[li] = g[u]; g[u] = li; li++;
		l[li] = u; lw[li] = w, ln[li] = g[v]; g[v] = li; li++;
		deg[v]++; deg[u]++;
		s += 2*w;
	}

	memset(b, 0, sizeof(b));
	dfs(0, 0);

	printf("%I64d", s - mm);
	
	return 0;
}
