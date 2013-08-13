#include <stdio.h>
#include <string.h>

short p[500], h[500], g[500][500], lca[500][500], gm[500][500];
char b[500];

inline int max(int a, int b) {
	return a > b ? a : b;
}

inline int min(int a, int b) {
	return a < b ? a : b;
}

inline short geth(short u) {
	if (h[u] == -1)
		h[u] = p[u] == -1 ? 0 : geth(p[u]) + 1;

	return h[u];
}

inline short getlca(short u, short v) {
	if (lca[u][v] == -1)
		lca[u][v] = h[u] < h[v] ? getlca(u, p[v]) : 
			h[u] > h[v] ? getlca(p[u], v) :
			u == v ? u :
				getlca(p[u], p[v]);
	
	return lca[u][v];
}

int main() {
	const int iinf = 0x7f7f7f7f;
	const short sinf = 0x7f7f;
	short n, u, v, w, mm, d[500];
	int i, m, l, ll;

	scanf("%hd%d", &n, &m);

	memset(g, 0x7f, sizeof(g));

	for (i = 0; i < m; i++) {
		scanf("%hhd%hhd%hd", &u, &v, &mm); u--; v--;
		g[u][v] = g[v][u] = mm;
	}

	memset(b, 0, sizeof(b));
	memset(p, 0, sizeof(p));
	memcpy(d, &g[0], sizeof(d));

	b[0] = 1;
	d[0] = 0;
	p[0] = -1;
	
	l = 0;
	for (i = 1; i < n; i++) {
		mm = sinf;
		for (u = 0; u < n; u++)
			if (!b[u] && d[u] < mm) {
				mm = d[u];
				v = u;
			}

		b[v] = 1;
		l += mm;

		for (u = 0; u < n; u++)
			if (!b[u] && g[v][u] < d[u]) {
				d[u] = g[v][u];
				p[u] = v;
			}
	}

	memset(h, 0xff, sizeof(h));
	for (u = 0; u < n; u++)
		h[u] = geth(u);
	
	memset(lca, 0xff, sizeof(lca));

	memset(gm, 0x7f, sizeof(gm));
	for (u = 0; u < n; u++) {
		v = u;
		mm = 0;
		while (p[v] != -1) {
			mm = max(mm, g[v][p[v]]);
			v = p[v];
			gm[u][v] = gm[v][u] = mm;
		}
	}

	ll = iinf;
	for (u = 0; u < n; u++)
		for (v = u + 1; v < n; v++) {
			if (gm[u][v] == sinf) {
				w = getlca(u, v);
				gm[u][v] = max(gm[w][u], gm[w][v]);
			}
			if (g[u][v] != sinf && p[u] != v && p[v] != u)
				ll = min(ll, l - gm[u][v] + g[u][v]);
		}

	printf("Cost: %d\nCost: %d\n", l, ll == iinf ? -1 : ll);
	
	return 0;
}
