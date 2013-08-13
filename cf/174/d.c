#include <stdbool.h>
#include <stdio.h>

typedef struct vertex vertex;
typedef struct edge edge;

struct vertex { int f; edge *i, *o; bool b, b1, b2; };
struct edge { vertex *v; edge *n; };

vertex vs[100000];
edge es[2*100000];

void go1(vertex *u) {
	u->b1 = true;
	u->b = true;

	for (edge *e = u->o; e != NULL; e = e->n) {
		vertex *v = e->v;

		if (!v->b && (v->f == 0 || v->f == 2))
			go1(v);
	}
}

void go2(vertex *u) {
	u->b2 = true;
	u->b = true;

	for (edge *e = u->i; e != NULL; e = e->n) {
		vertex *v = e->v;

		if (!v->b)
			if (v->f == 0 || v->f == 2)
				go2(v);
			else
				v->b2 = true;
	}
}

int main() {
	int n, m; scanf("%d%d", &n, &m);

	for (vertex *v = vs; v != vs+n; v++)
		scanf("%d", &v->f);

	edge *e = es;
	for (int i = 0; i < m; i++) {
		int ui, vi; scanf("%d%d", &ui, &vi); ui--; vi--;

		vertex *u = vs+ui, *v = vs+vi;
		*e = (edge){v, u->o}; u->o = e; e++;
		*e = (edge){u, v->i}; v->i = e; e++;
	}

	for (vertex *v = vs; v != vs+n; v++)
		v->b = false;
	for (vertex *v = vs; v != vs+n; v++)
		if (v->f == 1)
			go1(v);

	for (vertex *v = vs; v != vs+n; v++)
		v->b = false;
	for (vertex *v = vs; v != vs+n; v++)
		if (v->f == 2)
			go2(v);

	for (vertex *v = vs; v != vs+n; v++)
		printf("%d\n", v->b1 && v->b2);

	return 0;
}
