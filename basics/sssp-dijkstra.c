#include <stdbool.h>
#include <stdio.h>

typedef struct vertex {
       	bool b; int d;
} vertex;

int min(int a, int b) { return a < b ? a : b; }

int main() {
	int n; scanf("%d", &n);

	int ws[n][n];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%d", &ws[i][j]);

	vertex vs[n];
	const int inf = (int)1e9;
	for (vertex *v = vs; v != vs+n; ++v) {
		v->b = false; v->d = inf;
	}

	int s; scanf("%d", &s);
	vs[s].d = 0;

	for (int i = 0; i < n; i++) {
		vertex *v = NULL;
		for (vertex *u = vs; u != vs+n; ++u)
			if (!u->b && (v == NULL || u->d < v->d))
				v = u;

		v->b = true;
		
		for (vertex *u = vs; u != vs+n; ++u)
			if (!u->b)
				u->d = min(u->d, v->d + ws[v-vs][u-vs]);
	}

	for (vertex *v = vs; v != vs+n; ++v)
		printf("%d\n", v->d);

	return 0;
}
