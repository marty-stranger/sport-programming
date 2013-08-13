#include <stdio.h>

typedef struct segm segm;
struct segm { int x1, y1, x2, y2; };

void order(int *a, int *b) {
	if (*a > *b) {
		int t = *a; *a = *b; *b = t;
	}
}

int main() {
	int n; scanf("%d", &n);

	segm ss[600];
	for (segm *s = ss; s != ss+n; s++) {
		scanf("%d%d%d%d", &s->x1, &s->y1, &s->x2, &s->y2);
		order(&s->x1, &s->x2);
		order(&s->y1, &s->y2);
	}

	int c = 0;
	for (segm *s = ss; s != ss+n; s++) if (s->x1 == s->x2)
		for (segm *t = s+1; t != ss+n; t++) if (t->x1 == t->x2) {
			int cc = 0;
			for (segm *r = ss; r != ss+n; r++) if (r->y1 == r->y2)
				if (s->y1 <= r->y1 && r->y1 <= s->y2 &&
						t->y1 <= r->y1 && r->y1 <= t->y2 &&
						r->x1 <= s->x1 && s->x1 <= r->x2 &&
						r->x1 <= t->x1 && t->x1 <= r->x2)
					cc++;

			c += cc*(cc-1)/2;
		}

	printf("%d\n", c);

	return 0;
}
