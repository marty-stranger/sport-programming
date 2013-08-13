#include <stdbool.h>
#include <stdio.h>

typedef struct edge edge;
typedef struct vertex vertex;

struct edge { vertex *v; edge *n; };
struct vertex { edge *a; int d[3]; };

int main() {
	int n, m; scanf("%d%d", &n, &m);

	vertex vs[100000] = {0};
	edge es[400000];

	edge *e = es;
	for (int i = 0; i < m; i++) {
		int ui, vi; scanf("%d%d", &ui, &vi); ui--; vi--;

		vertex *u = vs+ui, *v = vs+vi;
		*e = (edge){v, u->a}; u->a = e; e++;
		*e = (edge){u, v->a}; v->a = e; e++;
	}

	for (int i = 0; i < 3; i++) {
		const int inf = 1e9;
		for (vertex *v = vs; v != vs+n; v++)
			v->d[i] = inf;

		vs[i].d[i] = 0;

		vertex *q[100000], **qs = q, **qe = q;
		*qe++ = vs+i;

		while (qs != qe) {
			vertex *u = *qs++;

			for (edge *e = u->a; e != NULL; e = e->n) {
				vertex *v = e->v;

				if (v->d[i] == inf) {
					v->d[i] = u->d[i] + 1;
					*qe++ = v;
				}
			}
		}
	}

	for (vertex *u = vs; u != vs+n; u++) {
		bool f = true;
		for (vertex *v = vs; v != vs+n; v++)
			if (v->d[0] < u->d[0] && v->d[1] < u->d[1] ||
					v->d[0] < u->d[0] && v->d[2] < u->d[2] ||
					v->d[1] < u->d[1] && v->d[2] < u->d[2]) {
				f = false;
				break;
			}

		if (f) {
			puts("1");
			return 0;
		}
	}

	puts("2");

	return 0;
}
