#include <stdio.h>
#include <string.h>

int my[5000], g[5000][5000];
int n, x[5000], y[5000];
char b[5000];

void dfs(int u, int d) {
	int v;

	for (v = 0; v < n; v++)
		if (g[u][v] && !b[v]) {
			b[v] = 1;
			x[v] = d;
			y[v] = my[d];
			my[d]++;
			dfs(v, d + 1);
		}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &n);

	int i;
	memset(g, 0, sizeof(g));
	for (i = 0; i < n-1; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		u--; v--;
		g[u][v] = 1;
		g[v][u] = 1;
	}

	memset(b, 0, sizeof(b));
	memset(my, 0, sizeof(my));
	b[0] = 1;
	x[0] = y[0] = 0;
	dfs(0, 1);

	for (i = 0; i < n; i++)
		printf("%d %d\n", x[i], y[i]);

	return 0;
}
