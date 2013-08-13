#include <stdio.h>

#define inf 1000000000

int n;
int g[100][100];
int d[100], p[100];

void Dijkstra(int s) {
	int b[100];
	int u, v, i, l;

	for (u = 0; u < n; ++u) {
		b[u] = 1;
		p[u] = s;
		d[u] = g[s][u];
	}
	b[s] = 0;
	p[s] = -1;
	d[s] = 0;

	for (i = 1; i < n; ++i) {
		l = inf;
		for (u = 0; u < n; ++u)
			if (b[u] && d[u] < l) {
				l = d[u];
				v = u;
			}

		b[v] = 0;
		for (u = 0; u < n; ++u)
			if (b[u] && l + g[v][u] < d[u]) {
				d[u] = l + g[v][u];
				p[u] = v;
			}	
	}
}

int main() {
	int m, u, v, w, i, l, len, f, v0, w0, k, k1;
	int cycle[100], cycle1[100];

	scanf("%d", &n);
	while (n != -1) {
		for (u = 0; u < n; ++u)
			for (v = 0; v < n; ++v)
				g[u][v] = inf;

		scanf("%d", &m);
		for (i = 0; i < m; ++i) {
			scanf("%d%d%d", &u, &v, &l);
			--u; --v;

			if (l < g[u][v]) {
				g[u][v] = l;
				g[v][u] = l;
			}
		}

		len = inf;
		for (u = 0; u < n; ++u) {
			Dijkstra(u);

			f = 0;

			for (v = 0; v < n; ++v)
				for (w = 0; w < n; ++w)
					if (d[v] + d[w] + g[v][w] < len && p[v] != w && p[w] != v) {
						len = d[v] + d[w] + g[v][w];
						v0 = v; w0 = w;
						f = 1;
					}
			if (f) {
				v = v0; k = 0;
				while (v != -1) {
					cycle[k++] = v;
					v = p[v];
				}

				v = w0; k1 = 0;
				while (v != -1) {
					cycle1[k1++] = v;
					v = p[v];
				}
			}	
		}

		if (len != inf) {
			for (i = 0; i < k-1; ++i)
				printf("%d ", cycle[i]+1);
			for (i = k1-1; i > 0; --i)
				printf("%d ", cycle1[i]+1);
			printf("%d\n", cycle1[0]+1);	
		} else
			printf("No solution.\n");

		scanf("%d", &n);	
	}

	return 0;
}
