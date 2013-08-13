#include <stdio.h>

typedef struct bank bank;
struct bank { int x, w; };

int main() {
	int n, d; scanf("%d%d", &n, &d);

	bank bs[200000];
	for (bank *b = bs; b != bs+n; b++)
		scanf("%d%d", &b->x, &b->w);

	bank *c = bs, *mc = NULL, *m1 = NULL, *m2 = NULL;
	for (bank *b = bs; b != bs+n; b++) {
		while (c->x + d <= b->x) {
			if (mc == NULL || c->w > mc->w)
				mc = c;
			c++;
		}

		if (mc != NULL)
			if (m1 == NULL || b->w + mc->w > m1->w + m2->w) {
				m1 = b; m2 = mc;
			}
	}

	if (m1 == NULL)
		puts("-1 -1");
	else
		printf("%d %d\n", m1-bs+1, m2-bs+1);

	return 0;
}
