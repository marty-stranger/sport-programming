#include <stdio.h>
#include <stdlib.h>

typedef struct { long long v; int i; } pair;

int a[200000];
pair ps[200000 + 1];

int less(pair p1, pair p2) {
	return p1.v < p2.v || (p1.v == p2.v && p1.i < p2.i);
}

void sort(int l, int r) {
	if (l >= r)
		return;

	int i = l, j = r, m = l + rand()%(r-l+1);
	pair p = ps[m];

	while (i <= j)
		if (less(ps[i], p))
			i++;
		else if (less(p, ps[j]))
			j--;
		else {
			pair t = ps[i]; ps[i] = ps[j]; ps[j] = t;
			i++; j--;
		}

	sort(l, j); sort(i, r);
}

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	for (int i = 0; i < n; i++)
		if (a[i] == 0) {
			printf("%d %d\n", i + 1, 1);
			return 0;
		}

	ps[0] = (pair){0, 0};
	for (int i = 0; i < n; i++)
		ps[i + 1] = (pair){ps[i].v + a[i], i + 1};

	/* for (int i = 0; i <= n; i++) {
		printf("%d %d\n", ps[i].v, ps[i].i);
	} */

	// printf("ok\n");

	sort(0, n);

	/* for (int i = 0; i <= n; i++) {
		printf("%d %d\n", ps[i].v, ps[i].i);
	}

	printf("ok\n"); */

	int m = 1000000000;
	int mi = -1;

	for (int i = 0; i < n; i++) {
		// printf("%d %d\n", ps[i].v, ps[i].i);

		if (ps[i].v == ps[i + 1].v && ps[i+1].i - ps[i].i < m) {
			m = ps[i+1].i - ps[i].i;
			mi = i;
		}
	}

	if (mi == -1) {
		printf("%d\n", -1);
		return 0;
	}

	printf("%d %d", ps[mi].i + 1, m);

	return 0;
}
