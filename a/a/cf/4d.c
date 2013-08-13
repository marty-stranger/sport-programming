#include <stdio.h>

typedef struct card { int w, h, b, n, c; } card;

int n;
card cs[5001];

int in(card *c, card *d) {
	return c->w < d->w && c->h < d->h;
}

void go(card *c) {
	c->b = 1;

	c->c = 1;
	c->n = -1;
	for (int i = 0; i < n; i++) {
		card *d = &cs[i];
		if (in(c, d)) {
			if (!d->b)
				go(d);

			if (d->c+1 > c->c) {
				c->c = d->c+1;
				c->n = i;
			}
		}
	}
}

int main() {
	int w, h; scanf("%d%d%d", &n, &w, &h);

	cs[n] = (card){w, h};
	for (int i = 0; i < n; i++) {
		int w, h; scanf("%d%d", &w, &h);
		cs[i] = (card){w, h};
	}

	go(&cs[n]);

	printf("%d\n", cs[n].c-1);

	int i = n;
	while (i != -1) {
		if (i != n)
			printf("%d ", i+1);
		i = cs[i].n;
	}
	putchar('\n');

	return 0;
}
