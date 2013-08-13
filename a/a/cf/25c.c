#include <stdio.h>

int min(int a, int b) {
	return a < b ? a : b;
}

int main() {
	int n;
	scanf("%d", &n);

	int i, j, d[300][300];
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			scanf("%d", &d[i][j]);

	int k;
	scanf("%d", &k);

	int ki;
	for (ki = 0; ki < k; ki++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		u--; v--;

		int uu, vv;
		long long s = 0;
		for (uu = 0; uu < n; uu++)
			for (vv = 0; vv < n; vv++) {
				d[uu][vv] = min(d[uu][vv], d[uu][u] + w + d[v][vv]);
				d[uu][vv] = min(d[uu][vv], d[uu][v] + w + d[u][vv]);
				s += (long long)d[uu][vv];
			}

		s /= 2;
		printf("%I64d ", s);
	}

	putchar('\n');

	return 0;
}
