#include <stdio.h>
#include <string.h>

int c[3][100000][3], p[3][100000][3];

int main() {
	int n, m, i, j, k, u, v, w, x, y, t, g[100000][4], d[100000],
		an, a[100000][2], av[100000], vc[100000],
		c0, ci, cj, cc, mm, mci, mcj, lc[100000];

	scanf("%d%d", &n, &m);

	memset(g, -1, sizeof(g));
	memset(d, 0, sizeof(d));

	for (i = 0; i < m; i++) {
		scanf("%d%d", &u, &v); u--; v--;
		g[u][d[u]++] = v;
		g[v][d[v]++] = u;
	}

	for (u = 0; u < n; u++)
		if (d[u] == 4)
			break;

	an = 0;
	av[an++] = u;

	v = g[u][0];
	while (d[v] != 4)
		t = v, v = g[v][0] + g[v][1] - u, u = t;

	memset(a, 0, sizeof(a));
	while (1) {
		j = 0;
		for (i = 0; i < 4; i++) {
			x = v; y = g[v][i];
			while (d[y] != 4)
				t = y, y = g[y][0] + g[y][1] - x, x = t;

			if (y != av[an-1])
				w = y;
			else {
				t = x; x = y; y = t;
				while (d[y] != 4) {
					vc[y] = an-1;
					t = y, y = g[y][0] + g[y][1] - x, x = t;
					a[an-1][j]++;
				}
				j++;
			}
		}

		if (v == av[0])
			break;
		av[an++] = v;
		v = w;
	}

	for (c0 = 0; c0 < 3; c0++)
		for (ci = 0; ci < 3; ci++)
			if (c0 == ci)
				c[c0][0][ci] = c0 != 0;
			else
				c[c0][0][ci] = -1;

	for (c0 = 0; c0 < 3; c0++)
		for (i = 1; i < an; i++)
			for (ci = 0; ci < 3; ci++) {
				c[c0][i][ci] = -1;
				for (cj = 0; cj < 3; cj++) {
					if (c[c0][i-1][cj] == -1)
						continue;

					cc = c[c0][i-1][cj] + a[i-1][0] + a[i-1][1] + (ci != 0);

					if (ci != 0 && cj != 0)
						if (ci != cj)
							cc -= (a[i-1][0] % 2 != 0) + (a[i-1][1] % 2 != 0);
						else
							if (a[i-1][0] == 0 || a[i-1][1] == 0)
								continue;
							else
								cc -= (a[i-1][0] % 2 == 0) + (a[i-1][1] % 2 == 0);

					if (cc > c[c0][i][ci])
						c[c0][i][ci] = cc, p[c0][i][ci] = cj;
				}
			}

	mm = -1;
	for (ci = 0; ci < 3; ci++)
		for (cj = 0; cj < 3; cj++) {
			cc = c[ci][an-1][cj] + a[an-1][0] + a[an-1][1];

			if (ci != 0 && cj != 0)
				if (ci != cj)
					cc -= (a[an-1][0] % 2 != 0) + (a[an-1][1] % 2 != 0);
				else
					if (a[an-1][0] == 0 || a[an-1][1] == 0)
						continue;
					else
						cc -= (a[an-1][0] % 2 == 0) + (a[an-1][1] % 2 == 0);

			if (cc > mm)
				mm = cc, mci = ci, mcj = cj;
		}

	u = av[0]; ci = mcj;
	lc[u] = mci;
	for (i = an - 1; i >= 0; i--) {
		v = av[i];
		lc[v] = ci;
		for (j = 0; j < 4; j++) {
			x = u; y = g[u][j];
			while (d[y] != 4)
				t = y, y = g[y][0] + g[y][1] - x, x = t;

			if (y == v) {
				if (lc[u] != 0) {
					x = u; y = g[u][j];
				} else {
					t = x; x = y; y = t;
				}

				while (d[y] != 4) {
					if (lc[x] == 0)
						lc[y] = 1;
					else
						lc[y] = 3 - lc[x];

					t = y, y = g[y][0] + g[y][1] - x, x = t;
				}

				if (lc[y] != 0 && lc[x] == lc[y])
					lc[x] = 0;
			}
		}
		u = v;
		ci = p[mci][i][ci];
	}

	k = 0;
	for (i = 0; i < n; i++)
		if (lc[i] == 1)
			k++;

	printf("%d", k);
	for (i = 0; i < n; i++)
		if (lc[i] == 1)
			printf(" %d", i + 1);
	putchar('\n');

	k = 0;
	for (i = 0; i < n; i++)
		if (lc[i] == 2)
			k++;

	printf("%d", k);
	for (i = 0; i < n; i++)
		if (lc[i] == 2)
			printf(" %d", i + 1);
	putchar('\n');

	return 0;
}

