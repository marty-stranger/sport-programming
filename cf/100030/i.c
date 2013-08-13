#include <stdbool.h>
#include <stdio.h>

typedef struct edge edge;
typedef struct vertex vertex;

struct edge { vertex *v; edge *n; };
struct vertex { edge *a; int m01, m1, mc; vertex *p; bool b; int i; };

const int inf = 1e9;

int min(int a, int b) { return a < b ? a : b; }

void go(vertex *u, vertex *w) {
	// printf("i = %d\n", u->i);
	int s = 0;
	u->m1 = 1;
	for (edge *e = u->a; e != NULL; e = e->n) {
		vertex *v = e->v;
		if (v != w) {
			go(v, u);
			s += v->m01;
			u->m1 += v->mc;
		}
	}

	u->mc = min(u->m1, s);

	u->m01 = u->m1; u->p = NULL;
	for (edge *e = u->a; e != NULL; e = e->n) {
		vertex *v = e->v;
		if (v != w) {
			int m = s - v->m01 + v->m1;
			if (m < u->m01) {
				u->m01 = m;
				u->p = v;
			}
		}
	}

	printf("i = %d -> m1 = %d mc = %d m01 = %d\n", u->i, u->m1, u->mc, u->m01);
}

void backtrace(vertex *u, vertex *w, bool b, bool c) {
	if (b || !b && c && u->mc == u->m1 || !b && !c && u->m01 == u->m1) {
		u->b = true;
		for (edge *e = u->a; e != NULL; e = e->n) {
			vertex *v = e->v;
			if (v != w)
				backtrace(v, u, false, true);
		}
	} else if (c) {
		u->b = false;
		for (edge *e = u->a; e != NULL; e = e->n) {
			vertex *v = e->v;
			if (v != w)
				backtrace(v, u, false, false);
		}
	} else {
		u->b = false;
		for (edge *e = u->a; e != NULL; e = e->n) {
			vertex *v = e->v;
			if (v != w)
				if (v == u->p)
					backtrace(v, u, true, false);
				else
					backtrace(v, u, false, false);
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n; scanf("%d", &n);

	edge es[2*10000];
	vertex vs[10000];

	for (int i = 0; i < n; i++)
		vs[i].i = i;

	for (int i = 0; i < n-1; i++) {
		int ui, vi; scanf("%d%d", &ui, &vi); ui--; vi--;
		vertex *u = vs+ui, *v = vs+vi;
		es[2*i] = (edge){u, v->a}; v->a = &es[2*i];
		es[2*i+1] = (edge){v, u->a}; u->a = &es[2*i+1];
	}

	go(&vs[0], NULL);

	// printf("%d\n", min(vs[0].r, vs[0].e));

	backtrace(&vs[0], NULL, false, false);

	for (int i = 0; i < n; i++)
		printf("%d ", vs[i].b);
	putchar('\n');

	return 0;
}
