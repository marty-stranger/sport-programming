#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct vertex vertex;

typedef struct edge edge;
struct edge { vertex *u, *v; int i, w, l; edge *n; };

edge es[200000];

void sort(int l, int r) {
	if (l < r) {
		int i = l, j = r, m = l + rand()%(r-l+1);
		int w = es[m].w;

		while (i <= j)
			if (es[i].w < w)
				i++;
			else if (w < es[j].w)
				j--;
			else {
				edge e = es[i]; es[i] = es[j]; es[j] = e;
				i++; j--;
			}

		sort(i, r); sort(l, j);
	}
}

typedef struct vertex vertex; 
struct vertex { vertex *p; int s; };

int n;
vertex vs[2000];

void init() {
	for (vertex *v = vs; v != vs+n; v++)
		*v = (vertex){v, 1};
}

vertex* find(vertex *u) {
	if (u->p != u)
		u->p = find(u->p);

	return u->p;
}

bool unite(vertex *u, vertex *v) {
	u = find(u); v = find(v);
	if (u != v) {
		if (u->s < v->s) {
			vertex *t = u; u = v; v = t;
		}

		v->p = u;
		u->s += v->s;
		return true;
	}

	return false;
}

typedef struct res res;
struct res { int w, l, n, ops[2000]; };

int main() {
	int ln, m; scanf("%d%d%d", &n, &ln, &m);

	for (edge *e = es; e != es+m; e++) {
		int ui, vi, l, w; 
		scanf("%d%d%d%d", &ui, &vi, &l, &w);
		ui--; vi--; l--;

		vertex *u = &vs[ui], *v = &vs[vi];
		*e = (edge){u, v, e-es, w, l};
	}

	sort(0, m-1);

	edge *ls[2000] = {0};
	for (edge *e = es; e != es+m; e++) {
		e->n = ls[e->l]; ls[e->l] = e;
	}

	init();

	edge t[2000-1]; int ti = 0;
	for (edge *e = es; e != es+m; e++)
		if (unite(e->u, e->v))
			t[ti++] = *e;

	res mr; mr.w = 1e9;
	for (int i = 0; i < ln; i++) {
		init();

		for (edge *e = ls[i]; e != NULL; e = e->n)
			unite(e->u, e->v);

		res r = {0, i, 0};
		for (edge *e = t; e != t+n-1; e++)
			if (unite(e->u, e->v)) {
				r.w += e->w;
				r.ops[r.n++] = e->i;
			}

		if (r.w < mr.w)
			mr = r;
	}

	printf("%d %d %d\n", mr.w, mr.l+1, mr.n);
	for (int i = 0; i < mr.n; i++)
		printf("%d ", mr.ops[i]+1);
	putchar('\n');

	return 0;
}
