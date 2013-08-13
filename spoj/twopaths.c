#include <stdio.h>

typedef struct vertex vertex;
typedef struct edge edge;

struct edge { vertex *u; edge *n; };
struct vertex { edge *a; int d, h, i; };

int max(int a, int b) { return a > b ? a : b; }
long long maxll(long long a, long long b) { return a > b ? a : b; }

void dfs(vertex *u, vertex *w) {
	int h1 = 0, h2 = 0, d = 0;
	for (edge *e = u->a; e != NULL; e = e->n) {
		vertex *v = e->u;
		if (v != w) {
			dfs(v, u);
			int h = v->h + 1;
			if (h > h1)
				h2 = h1, h1 = h;
			else if (h > h2)
				h2 = h;

			d = max(d, v->d);
		}
	}

	u->h = h1;
	u->d = max(d, h1+h2);

}

long long a = 0;
vertex *v;
int h, mm, d, dd;

void dfs2(vertex *u, vertex *w, int m, int l) {
	int d1 = 0, d2 = 0, h1 = 0, h2 = 0, h3 = 0;
	for (edge *e = u->a; e != NULL; e = e->n) {
		v = e->u;
		if (v != w) {
			h = v->h + 1;
			if (h > h1)
				h3 = h2, h2 = h1, h1 = h;
			else if (h > h2)
				h3 = h2, h2 = h;
			else if (h > h3)
				h3 = h;

			d = v->d;
			if (d > d1)
				d2 = d1, d1 = d;
			else if (d > d2)
				d2 = d;
		}
	}

	for (edge *e = u->a; e != NULL; e = e->n) {
		v = e->u;
		if (v != w) {
			mm = m;

			if (v->d == d1)
				mm = max(mm, d2);
			else
				mm = max(mm, d1);

			h = v->h + 1;
			if (h == h1)
				mm = max(mm, h2+h3);
			else if (h == h2)
				mm = max(mm, h1+h3);
			else
				mm = max(mm, h1+h2);

			if (h == h1)
				mm = max(mm, d+h2), ll = max(l, h2) + 1;
			else
				mm = max(mm, d+h1), ll = max(l, h1) + 1;

			a = maxll(a, 1ll * mm * v->d);

			dfs2(v, u, mm, ll);
		}
	}
}

edge es[2*100000];
vertex vs[100000];

int main() {
	int n; scanf("%d", &n);

	for (int i = 0; i < n; i++)
		vs[i].i = i, vs[i].a = NULL;

	for (int i = 0; i < n-1; i++) {
		int ui, vi; scanf("%d%d", &ui, &vi); ui--; vi--;
		vertex *u = &vs[ui], *v = &vs[vi];

		es[2*i] = (edge){v, u->a}; u->a = &es[2*i];
		es[2*i+1] = (edge){u, v->a}; v->a = &es[2*i+1];
	}

	dfs(&vs[0], NULL);

	dfs2(&vs[0], NULL, 0, 0);

	printf("%lld\n", a);

	return 0;
}
