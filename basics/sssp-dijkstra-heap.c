#include <stdio.h>

typedef struct vertex vertex;
typedef struct edge edge;

struct edge { vertex *v; int w; edge *n; };
struct vertex { edge *a; bool b; int i, d; };

void heap_insert() {
}

int main() {
	int n, m; scanf("%d%d", &n, &m);

	edge es[2*m];
	for (int i = 0; i < m; i++) {
		int vi, ui, w; scanf("%d%d%d", &vi, &ui, &w);

		vertex *v = &vs[vi], *u = &vs[ui];
		es[2*i] = (edge){u, w, v->a}; v->a = &es[2*i];
		es[2*i+1] = (edge){v, w, u->a}; u->a = &es[2*i+1];
	}

	const int inf = (int)1e9;
	for (vertex *v = vs; v != vs+n; v++) {
		v->i = v - vs;
		v->d = inf;
		v->b = false;
		heap_insert(v);
	}

	int s; scanf("%d", &s);
	vs[s]->d = 0;

	for (int i = 0; i < n; i++) {
		vertex *v = heap_extract();

		v->b = true;

		for (edge *e = v->a; e != NULL; e = e->n) {
			vertex *u = e->v;
			if (!u->b && v->d + e->w < u->d) {
				u->d = v->d + e->w;
				heap_decrease(u);
			}
		}
	}

	return 0;
}
