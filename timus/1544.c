// ok
#include <stdio.h>
#include <string.h>

int n, ct[50], g[50][50];

void dfs(int u) {
	int v;

	ct[u] = !ct[u];

	for (v = 0; v < n; v++)
		if (g[u][v] && ct[v] != ct[u])
			dfs(v);
}

int main() {
	int m, i, u, v, s, mm, mmm, mu, c[50];
	char ch[2];

	scanf("%d%d", &n, &m);
	for (u = 0; u < n; u++) {
		scanf("%s", ch);
		c[u] = ch[0] == 'E';
	}

	memset(g, 0, sizeof(g));
	for (i = 0; i < m; i++) {
		scanf("%d%d", &u, &v); u--; v--;
		g[u][v] = g[v][u] = 1;
	}

	mm = 1000000000;
	for (u = 0; u < n; u++) {
		memcpy(ct, c, sizeof(c));

		mmm = 0;
		s = 0;
		for (v = 0; v < n; v++)
			s += ct[v];

		while (s != 0 && s != n) {
			dfs(u);
			mmm++;

			s = 0;
			for (v = 0; v < n; v++)
				s += ct[v];
		}

		if (mmm < mm) {
			mm = mmm;
			mu = u;
		}
	}

	printf("%d\n", mm);
	for (i = 0; i < mm; i++) {
		c[mu] = !c[mu];
		printf("%d %c\n", mu + 1, c[mu] ? 'E' : 'J');
	}

	return 0;
}

