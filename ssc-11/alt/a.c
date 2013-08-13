// acc, KD said O(n + m) exists
// http://codeforces.ru/blog/entry/2923#comment-59335
#include <stdio.h>

int main() {
	const int inf = 1000000000;
	int n, m, i, u, v, w, f, qs, qe, g[100000], ln[400000], l[400000], d[3][100000], q[100000];

	scanf("%d%d", &n, &m);

	f = 0;
	for (u = 0; u < n; u++)
		g[u] = -1;

	for (i = 0; i < m; i++) {
		scanf("%d%d", &u, &v);
		u--; v--;

		l[f] = v; ln[f] = g[u];
		g[u] = f;
		f++;

		l[f] = u; ln[f] = g[v];
		g[v] = f;
		f++;
	}

	for (w = 0; w < 3; w++) {
		for (u = 0; u < n; u++)
			d[w][u] = inf;

		qs = qe = 0;
		q[qe] = w; qe++;

		d[w][w] = 0;

		while (qs != qe) {
			u = q[qs]; qs++;

			for (i = g[u]; i != -1; i = ln[i]) {
				v = l[i];

				if (d[w][v] == inf) {
					d[w][v] = d[w][u] + 1;
					q[qe] = v; qe++;
				}
			}
		}
	}

	for (u = 0; u < n; u++) {
		for (v = 0; v < n; v++) 
			if (d[0][v] < d[0][u] && d[1][v] < d[1][u] ||
					d[0][v] < d[0][u] && d[2][v] < d[2][u] ||
					d[1][v] < d[1][u] && d[2][v] < d[2][u])
				break;

		if (v == n) {
			printf("1\n");
			return 0;
		}
	}

	printf("2\n");
	return 0;
}
