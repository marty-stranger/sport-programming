#include <stdio.h>

typedef struct vertex { int b, e, an; struct vertex *a[200]; } vertex;
vertex vs[200];

int dfs(vertex *v, vertex *w, vertex *t) {
	if (v == t) {
		v->e = 0;
		return 0;
	}
	
	v->b = 1;

	for (int l = 0; l < v->an; l++) {
		vertex *u = v->a[l];
       		if (u != w && !u->b) {
			int d = dfs(u, v, t);
			if (d >= 0) {
				v->e = 0;
				return d + 1;
			}
		}
	}

	return -1;
}

int md = 0;
int dfs2(vertex *v, vertex *w) {
	v->b = 1;
	
	int m = 0, d1 = 0, d2 = 0;
	for (int l = 0; l < v->an; l++) {
		vertex *u = v->a[l];
		if (u != w && u->e && !u->b) {
			int d = dfs2(u, v);
			if (d+1 > m)
				m = d+1;
			if (d1 > d2 && d+1 > d2)
				d2 = d+1;
			else if (d1 < d2 && d+1 > d1)
				d1 = d+1;
			else if (d1 == d2 && d+1 > d1)
				d1 = d+1;
		}
	}

	if (d1+d2 > md)
		md = d1+d2;
	
	return m;
}

int main() {
	int n; scanf("%d", &n);

	for (int i = 0; i < n-1; i++) {
		int a, b; scanf("%d%d", &a, &b); a--; b--;

		vertex *u = &vs[a], *v = &vs[b];
		u->a[u->an++] = v; v->a[v->an++] = u;
	}

	int m = 0;
	for (int i = 0; i < n; i++)
		for (int j = i+1; j < n; j++) {
			for (int k = 0; k < n; k++)
				vs[k].b = 0, vs[k].e = 1;
			int d1 = dfs(&vs[i], NULL, &vs[j]);

			for (int k = 0; k < n; k++)

			for (int k = 0; k < n; k++)
				vs[k].b = 0;

			int d2 = 0;
			for (int k = 0; k < n; k++) {
				vertex *v = &vs[k];
				if (v->e && !v->b) {
					md = 0;
					dfs2(v, NULL);
					if (md > d2)
						d2 = md;
				}
			}

			if (d1*d2 > m)
				m = d1*d2;
		}

	printf("%d\n", m);

	return 0;
}
