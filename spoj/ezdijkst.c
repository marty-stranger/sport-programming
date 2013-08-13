#include <stdbool.h>
#include <stdio.h>

typedef struct edge edge;
typedef struct vertex vertex;

struct edge { vertex *v; int w; edge *n; };
struct vertex { edge *a; bool b; int d, hi; };

typedef struct { int n; vertex *a[10000]; } heap;

int less(vertex *v, vertex *u) {
	return v->d < u->d;
}

void move(heap *h, int i, vertex *v) {
	h->a[i] = v; v->hi = i;
}

void down(heap *h, int i) {
	vertex *v = h->a[i];

	while (2*i+1 < h->n) {
		int j = 2*i+1;
		if (j+1 < h->n && less(h->a[j+1], h->a[j]))
			j++;

		if (!less(h->a[j], v))
			break;

		move(h, i, h->a[j]);
		i = j;
	}

	move(h, i, v);
}

vertex *extract(heap *h) {
	vertex *v = h->a[0];

	move(h, 0, h->a[h->n-1]); h->n--;

	down(h, 0);

	return v;
}

void up(heap *h, int i) {
	vertex *v = h->a[i];

	while (i != 0) {
		int j = (i-1)/2;
	       	if (!less(v, h->a[j]))
			break;

		move(h, i, h->a[j]);
		i = j;
	}

	move(h, i, v);
}

void decrease(heap *h, vertex *v) {
	up(h, v->hi);
}

void insert(heap *h, vertex *v) {
	move(h, h->n, v); h->n++;
	up(h, v->hi);
}

int main() {
	int cn; scanf("%d", &cn);

	for (int ci = 0; ci < cn; ci++) {
		int n, m; scanf("%d%d", &n, &m);

		edge es[m];
		vertex vs[n];

		for (vertex *v = vs; v != vs+n; v++)
			v->a = NULL;

		for (int i = 0; i < m; i++) {
			int ui, vi, w; scanf("%d%d%d", &ui, &vi, &w); ui--; vi--;

			vertex *u = &vs[ui], *v = &vs[vi];
			es[i] = (edge){v, w, u->a}; u->a = &es[i];
		}

		int s, t; scanf("%d%d", &s, &t); s--; t--;

		const int inf = (int)1e9;
		for (vertex *v = vs; v != vs+n; v++) {
			v->d = inf; v->b = false;
		}

		vs[s].d = 0;

		heap h; h.n = 0;
		for (vertex *v = vs; v != vs+n; v++)
			insert(&h, v);

		for (int i = 0; i < n; i++) {
			vertex *v = extract(&h);
			v->b = true;

			for (edge *e = v->a; e != NULL; e = e->n) {
				vertex *u = e->v;
				if (!u->b && v->d + e->w < u->d) {
					u->d = v->d + e->w;
					decrease(&h, u);
				}
			}
		}

		vertex *v = &vs[t];
		if (v->d == inf)
			puts("NO");
		else
			printf("%d\n", v->d);
	}

	return 0;
}
