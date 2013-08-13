#include <stdbool.h>
#include <stdio.h>

typedef struct { long long d; int s; } edge;
typedef struct { long long d; bool b; int i; } vertex;

const long long inf = (long long)1e18;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int n, m; scanf("%d%d", &n, &m);

	static edge g[1000][1000];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			g[i][j].s = g[i][j].d = inf;

	for (int i = 0; i < m; i++) {
		int ui, vi, d, s;
		scanf("%d%d%d%d", &ui, &vi, &d, &s); ui--; vi--;

		g[ui][vi] = g[vi][ui] = (edge){d, s};
	}

	int t; scanf("%d", &t);

	int l = 1, r = (int)1e6; int d;
	bool f = false;
	while (l < r) {
		int m = (l+r)/2;

		vertex vs[1000];
		for (int i = 0; i < n; i++)
			vs[i] = (vertex){inf, false, i};
		vs[0].d = 0;

		for (int i = 0; i < n; i++) {
			vertex *u = NULL;
			for (vertex *v = vs; v != vs+n; v++)
				if (!v->b && (u == NULL || v->d < u->d))
					u = v;

			u->b = true;

			for (vertex *v = vs; v != vs+n; v++)
				if (!v->b) {
					edge *e = &g[u->i][v->i];
					if (e->s <= m && u->d + e->d < v->d)
						v->d = u->d + e->d;
				}
		}

		if (vs[n-1].d <= t) {
			f = true;
			d = vs[n-1].d;
			r = m;
		} else
			l = m+1;
	}

		m = l;
		vertex vs[1000];
		for (int i = 0; i < n; i++)
			vs[i] = (vertex){inf, false, i};
		vs[0].d = 0;

		for (int i = 0; i < n; i++) {
			vertex *u = NULL;
			for (vertex *v = vs; v != vs+n; v++)
				if (!v->b && (u == NULL || v->d < u->d))
					u = v;

			u->b = true;

			for (vertex *v = vs; v != vs+n; v++)
				if (!v->b) {
					edge *e = &g[u->i][v->i];
					if (e->s <= m && u->d + e->d < v->d)
						v->d = u->d + e->d;
				}
		}

		if (vs[n-1].d <= t) {
			f = true;
			d = vs[n-1].d;
			l = m;
		}

	if (!f)
		puts("NO");
	else {
		puts("YES");
		printf("%d %d\n", l, d);
	}

	return 0;
}
