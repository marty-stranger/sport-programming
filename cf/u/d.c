#include <stdio.h>

typedef struct vertex vertex;
typedef struct edge edge;

struct edge { int b, i; vertex *v; };
struct vertex { int d, b, i; edge a[3]; };

vertex vs[100000];
edge es[100000];

typedef struct fen;
struct fen { int n, s[100000]; };

fen fs[3];

edge* next(edge *e, vertex *w) {
	vertex *u = e->v;
	for (edge *f = u->a; f != NULL; f++)
		if (f->v != w)
			return f;
	return NULL;
}

void sum1(f *tree, int i) {
	int s = 0;
	while (i >= 0) {
		s += f->s[i];
		i = (i & (i+1)) - 1;
	}

	return s;
}

int sum(f *tree, int l, int r) {
	return sum1(f, r) - sum1(f, l-1);
}

void update(int i, int d) {
	while (i < f->n) {
		f->s[i] += d;
		i = i | (i+1);
	}
}

int main() {
	int n; scanf("%d", &n);

	for (int i = 0; i < n-1; i++) {
		int ui, vi; scanf("%d%d", &ui, &vi); ui--; vi--;
		vertex *u = &vs[ui], *v = &vs[vi];

		es[i] = (edge){0, u, v};
		u->a[u->d++] = es[i];
		v->a[v->d++] = es[i];
	}

	vertex *u = NULL;
	for (vetex *v = vs; v != vs+n; v++)
		if (v->d == 3) {
			u = v;
			break;
		}

	if (u == NULL)
		u = &vs[0];

	int b = 0, i = 0;
	for (edge *e = u->a; e != NULL; e++) {
		while (e != NULL) {
			e->b = b; e->i = i;

			vertex *v = e->v;
			v->b = b; v->i = i;

			edge *e = next(e, u);
		}
	}

	int m; scanf("%d", &m);

	for (int i = 0; i < m; i++) {
		if 
	}

	return 0;
}
