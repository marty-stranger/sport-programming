#include <stdbool.h>
#include <stdio.h>

typedef struct square square;
struct square { int x, y; bool a, b; square *p; };

int n;
square b[40][40];

bool search(square *s) {
	s->b = true;

	const int dx[4] = {1, 0, -1, 0},
	      dy[4] = {0, 1, 0, -1};
	for (int i = 0; i < 4; i++) {
		int x = s->x + dx[i], y = s->y + dy[i];
		if (0 <= x && x < n && 0 <= y && y < n) {
			square *t = &b[x][y];
			if (t->a && (t->p == NULL || !t->p->b && search(t->p))) {
				t->p = s;
				return true;
			}
		}
	}

	return false;
}

bool black(square *s) {
	return (s->x + s->y) % 2 == 0;
}

int main() {
	int p; scanf("%d%d", &n, &p);

	for (int x = 0; x < n; x++)
		for (int y = 0; y < n; y++)
			b[x][y] = (square){x, y, true};

	for (int i = 0; i < p; i++) {
		int x, y; scanf("%d%d", &x, &y); x--; y--;
		b[x][y].a = false;
	}

	int c1 = 0, c2 = 0;
	for (square (*l)[40] = b; l != b+n; l++)
		for (square *s = *l; s != *l+n; s++)
			if (s->a)
				if (black(s))
					c1++;
				else
					c2++;

	if (c1 != c2) {
		puts("No");
		return 0;
	}

	int c = 0;
	for (square (*l)[40] = b; l != b+n; l++)
		for (square *s = *l; s != *l+n; s++)
			if (s->a && black(s)) {
				for (square (*l)[40] = b; l != b+n; l++)
					for (square *s = *l; s != *l+n; s++)
						if (black(s))
							s->b = false;

				if (search(s))
					c++;
			}

	if (c != c1) {
		puts("No");
		return 0;
	}

	int hn = 0, vn = 0;
	for (square (*l)[40] = b; l != b+n; l++)
		for (square *s = *l; s != *l+n; s++)
			if (s->p != NULL)
				if (s->p->y == s->y)
					hn++;
				else
					vn++;

	puts("Yes");
	printf("%d\n", hn);
	for (square (*l)[40] = b; l != b+n; l++)
		for (square *s = *l; s != *l+n; s++)
			if (s->p != NULL)
				if (s->p->y == s->y)
					if (s->x < s->p->x)
						printf("%d %d\n", s->x + 1, s->y + 1);
					else
						printf("%d %d\n", s->p->x + 1, s->p->y + 1);

	printf("%d\n", vn);
	for (square (*l)[40] = b; l != b+n; l++)
		for (square *s = *l; s != *l+n; s++)
			if (s->p != NULL)
				if (s->p->x == s->x)
					if (s->y < s->p->y)
						printf("%d %d\n", s->x + 1, s->y + 1);
					else
						printf("%d %d\n", s->p->x + 1, s->p->y + 1);

	return 0;
}
