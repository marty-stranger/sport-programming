// ok
#include <string.h>
#include <stdio.h>

inline int min(int a, int b) {
	return a < b ? a : b;
}

int main() {
	const int inf = 1000000000;
	int n, k, m, l, u0, v0, i, i1, j1, i2, j2, u, v, w1, w2, u1, u2, v1, v2, g[6][20][6][20], d[20][20], gg[6][20][6][20];

	memset(g, 0, sizeof(g));
	scanf("%d%d%d", &n, &k, &m);
	for (i = 0; i < m; i++) {
		scanf("%d.%d - %d.%d", &i1, &j1, &i2, &j2);
		g[i1][j1][i2][j2] = g[i2][j2][i1][j1] = 1;
	}
	scanf("%d%d", &u0, &v0);

	for (u = 0; u < n; u++)
		for (v = 0; v < n; v++)
			d[u][v] = u == v ? 0 : inf;

	for (l = 0; l < n; l++) {
		for (i1 = 0; i1 <= k; i1++)
			for (j1 = 0; j1 < n; j1++)
				for (i2 = 0; i2 <= k; i2++)
					for (j2 = 0; j2 < n; j2++) {
						gg[i1][j1][i2][j2] = inf;

						if (i1 == i2)
							gg[i1][j1][i2][j2] = d[j1][j2];
						if (g[i1][j1][i2][j2])
							gg[i1][j1][i2][j2] = 1;
					}

		for (w1 = 0; w1 <= k; w1++) for (w2 = 0; w2 < n; w2++)
			for (u1 = 0; u1 <= k; u1++) for (u2 = 0; u2 < n; u2++)
				for (v1 = 0; v1 <= k; v1++) for (v2 = 0; v2 < n; v2++)
					gg[u1][u2][v1][v2] = min(gg[u1][u2][v1][v2],
						gg[u1][u2][w1][w2] + gg[w1][w2][v1][v2]);

		for (u = 0; u < n; u++)
			for (v = 0; v < n; v++)
				d[u][v] = gg[0][u][0][v];
	}

	if (d[u0][v0] == inf)
		puts("no solution");
	else
		printf("%d", d[u0][v0]);
	
	return 0;
}
