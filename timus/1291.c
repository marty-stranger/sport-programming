#include <stdio.h>
#include <string.h>

int n, c[1000], b[1000], g[1000], p[1000], q[1000], ln[2000], lv[2000];

int gcd(int a, int b) {
	int c;

	if (a < 0)
		a = -a;

	while (b != 0) {
		c = a % b;
		a = b;
		b = c;
	}

	return a;
}

void dfs(int u) {
	int i, v, d, pp, qq;

	b[u] = 1;

	i = g[u];
	while (i != -1) {
		v = lv[i];
		if (!b[v]) {
			pp = -p[u] * c[u]; qq = q[u] * c[v];
			d = gcd(pp, qq); pp /= d; qq /= d;
			p[v] = pp; q[v] = qq;

			dfs(v);
		}
		i = ln[i];
	}
}

int main() {
	int u, v, i, s, vv, lf;

	scanf("%d", &n);
	for (i = 0; i < 2*n; i++)
		ln[i] = i + 1;
	lf = 0;
	for (u = 0; u < n; u++) {
		g[u] = -1;
		scanf("%d%d", &c[u], &v);
		while (v != 0) {
			v--;

			i = lf; lf = ln[lf];
			ln[i] = g[u]; g[u] = i;
			lv[i] = v;

			scanf("%d", &v);
		}
	}

	scanf("%d%d", &s, &vv); s--;

	for (u = 0; u < n; u++) {
		p[u] = 0;
		q[u] = 1;
	}
	p[s] = vv;
	
	memset(b, 0, sizeof(b));
	dfs(s);

	for (u = 0; u < n; u++)
		printf("%d/%d\n", p[u], q[u]);

	return 0;
}
