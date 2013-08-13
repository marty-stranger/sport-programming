#include <assert.h>
#include <stdio.h>

#ifndef __cplusplus
	#include <stdbool.h>
#endif 

#ifdef ONLINE_JUDGE
	#define debug(...)
#else
	#define debug(...) fprintf(stderr, __VA_ARGS__)
#endif

typedef struct vertex vertex;

enum color { white, grey, black };
typedef enum color color;

struct vertex { int i, an, wn, zn; vertex *m, *l, *n, *y, *p, *w[300], *a[300], *z[300]; color c; bool b; };

int n;

vertex vs[300];

int d = 0;

void ident() {
	for (int i = 0; i < d; i++)
		debug("\t");
}

void pair(vertex *u, vertex *v) {
	debug("pair %d and %d\n", u->i + 1, v->i + 1);
	u->m = v; v->m = u;
}

void add(vertex *u, vertex *v) {
	debug("w point %d to %d\n", u->i + 1, v->i + 1);
	u->w[u->wn++] = v;
}

void join(vertex *u, vertex *w) {
	debug("join %d to %d\n", u->i+1, w->i+1);
	u = u->l; w = w->l;

	for (vertex *v = vs; v != vs+n; v++)
		if (v->l == u)
			v->l = w;
}

int qn = 0;
vertex *q[300];

void mark(vertex *u, vertex *w) {
	if (u->b)
		return;

	debug("mark %d to %d\n", u->i + 1, w->i + 1);

	u->b = true;
	assert(qn < 300);
	q[qn++] = u;

	if (u->l != u) {
		vertex *v = u->l;
		debug("u.l = v = %d\n", v->i + 1);
		if (v != w) {
			mark(v->m, w);
		}
		
		return;
	}

	if (u->p != NULL) {
		vertex *v = u->p;
		debug("%d.p = %d\n", u->i + 1, v->i + 1);
		if (v != w) {
			mark(v->m, w);
		}
	}

	for (int i = 0; i < u->wn; i++) {
		vertex *v = u->w[i];
		debug("%d.w = %d\n", u->i + 1, v->i + 1);
		if (v != w) {
			mark(v->m, w);
		}	
	}
}

void fix(vertex *u, vertex *w) {
	if (u == w)
		return;

	debug("fix from %d to %d\n", u->i + 1, w->i + 1);

	vertex *v = u->m;
	debug("v = %d\n", v->i + 1);

	if (v->y != NULL) {
		vertex *y = v->y;
		vertex *p = v->p;
		assert(p != NULL);
		debug("y = %d p = %d\n", y->i + 1, p->i + 1);
		fix(y, v);
		fix(p, w);
		pair(y, p);
		return;
	}

	// debug("v.p = %d\n", v->p->i + 1);
	// debug("v.m = %d\n", v->m->i + 1);
	vertex *p = v->p;
	// assert(v->c = white);
	assert(p != NULL);
	fix(p, w);
	pair(v, p);
}

bool go(vertex *u) {
	d++;

	ident();
	debug("visit %d\n", u->i + 1);
	assert(u->c == white);

	u->c = grey;

	for (int i = 0; i < u->an; i++) {
		vertex *v = u->a[i];

		if (v == u->m)
			continue;

		ident();
		debug("try %d -> %d\n", u->i + 1, v->i + 1);

		if (v->c == grey) {
			debug("odd %d to %d\n", v->i + 1, u->i + 1);
			v->z[v->zn++] = u;
			continue;
		}

		if (v->m == NULL) {
			debug("found end %d (1)\n", v->i + 1);
			assert(v->c == white);
			pair(u, v);
			return true;
		}

		if (v->m->c == white) {
			if (go(v->m)) {
				pair(u, v);
				return true;
			}

			v->p = u;
		} else if (v->m->c == grey) {
			debug("even\n");
			assert(v->c == white || v->c == black);
			add(v, u);
		} else {
			assert(v->m->c == black);
			if (v->c == white) {
				debug("even (2)/n");
				add(v, u);
			} else {
				if (v->l == v) {
					add(v, u);
				} else {
					vertex *w = v->l;
					debug("jump to %d\n", w->i + 1);
					if (w->m == NULL) {
						debug("found end %d (2)\n", w->i + 1);
						fix(v, w);
						pair(u, v);
						return true;
					}

					debug("%d\n", w->m->c + 1);
					if (w->m->c == grey) {
						debug("odd (2) %d to %d\n", v->i + 1, u->i + 1);
						v->z[v->zn++] = u;
					} else if (w->m->c == white) {
						if (go(w->m)) {
							fix(v, w);
							pair(u, v);
							return true;
						}

						assert(w->y == NULL);
						w->y = v;
						w->p = u;
						debug("!%d.p = %d\n", w->i + 1, u->i + 1);
					} else {
						add(w, u);
					}
				}

			}
		}
	}

	ident();
	debug("visted %d\n", u->i + 1);

	if (u->m == NULL || u->m->c == white) {
		debug("zn = %d\n", u->zn);

		for (vertex *v = vs; v != vs+n; v++)
			v->b = false;

		qn = 0;
		for (int i = 0; i < u->zn; i++) {
			vertex *v = u->z[i];
			debug("%d.z -> %d\n", u->i + 1, v->i + 1);
			mark(v->m, u);
		}

		for (vertex **v = q; v != q+qn; v++)
			join(*v, u);

		for (vertex *v = vs; v != vs+n; v++)
			debug("%d->%d ", v->i + 1, v->l->i + 1);
		debug("\n");
	}

	u->c = black;
	d--;

	return false;
}

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		vs[i].i = i;

	bool g[300][300] = {0};

	for (;;) {
		int ui, vi;
		if (scanf("%d%d", &ui, &vi) == EOF)
			break;

		ui--; vi--;

		if (ui == vi || g[ui][vi])
			continue;

		g[ui][vi] = g[vi][ui] = true;

		vertex *u = vs+ui, *v = vs+vi;
		u->a[u->an++] = v;
		v->a[v->an++] = u;
	}

	int c = 0;
	for (vertex *u = vs; u != vs+n; u++) {
		for (vertex *v = vs; v != vs+n; v++) {
			v->c = white;
			v->wn = v->zn = 0;
			v->l = v;
			v->p = v->n = v->y = NULL;
			v->b = false;
		}

		d = 0;

		debug("loop %d\n", u-vs+1);
		if (u->m == NULL && go(u))
			c++;

		for (vertex *v = vs; v != vs+n; v++)
			if (v->m != NULL && v->i < v->m->i)
				debug("%d-%d ", v->i + 1, v->m->i + 1);
		debug("\n\n");
	}

	printf("%d\n", 2*c);

	for (vertex *u = vs; u != vs+n; u++)
		if (u->m != NULL && u->i < u->m->i)
			printf("%d %d\n", u->i + 1, u->m->i + 1);

	return 0;
}
