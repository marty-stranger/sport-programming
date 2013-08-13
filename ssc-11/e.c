#include <stdio.h>

typedef struct vertex vertex;
typedef struct edge edge;
typedef struct item item;

struct vertex { int d; item *a; };
struct edge { int t, p; };
struct item { edge *e; vertex *v; item *n; }

int main() {
	int n; scanf("%d", &n);

	vertex vs[100000] = {0};
	edge es[200000];
	item list[200000];

	item *li = list;
	for (edge *e = es; e != es+n-1; e++) {
		int ui, vi; scanf("%d%d%d%d", &ui, &vi, &e->t, &e->p); ui--; vi--;

		vertex *u = vs+ui, *v = vs+vi;
		u->d++; v->d++;

		*li = (item){e, u, v->a}; v->a = li; li++;
		*li = (item){e, v, u->a}; u->a = li; li++;
	}

	if (n == 2) {
		printf("%d\n%d\n%d\n", es[0].p, 1, 1);
		return 0;
	}

	vertex *u;
	for (u = vs; u != vs+n; u++)
		if (u->d != 1)
			break;

	u->p = NULL;
	return 0;
}
