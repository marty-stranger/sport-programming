#include <stdio.h>

typedef struct heap heap;

struct heap { int n; int a[100000]; };

void init(heap *h) {
	h->n = 0;
}

void up(heap *h, int i) {
	int v = h->a[i];
	while (i != 0) {
		int j = (i-1)/2;

		if (!(v < h->a[j]))
			break;

		h->a[i] = h->a[j];
		i = j;
	}

	h->a[i] = v;
}

void insert(heap *h, int v) {
	h->a[h->n] = v; h->n++;
	up(h, h->n-1);
}

void down(heap *h, int i) {
	int v = h->a[i];
	while (2*i+1 < h->n) {
		int j = 2*i+1;
		if (j+1 < h->n && h->a[j+1] < h->a[j])
			j++;

		if (!(v > h->a[j]))
			break;

		h->a[i] = h->a[j];
		i = j;
	}

	h->a[i] = v;
}


int extract(heap *h) {
	int v = h->a[0];
	h->a[0] = h->a[h->n-1];
	h->n--;

	down(h, 0);

	return v;
}

void print(heap *h) {
	for (int *v = h->a; v != h->a + h->n; v++)
		printf("%d ", *v);
	putchar('\n');
}

int main() {
	heap h;

	init(&h);

	for (;;) {
		char c[100]; scanf("%s", c);
		switch (c[0]) {
			int v;

			case 'i':
				scanf("%d", &v);
				insert(&h, v);
				break;
			case 'e':
				printf("%d\n", extract(&h));
				break;
			// case 'd':
			//	int i, d; scanf("%d%d", &i, &d);
			//	decrease(&h, i, d);
			//	break;
			case 'p':
				print(&h);
				break;
		}
	}

	return 0;
}
