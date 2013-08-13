#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct { int l, r; } pair;

bool less(pair p1, pair p2) {
	return p1.l < p2.l || p1.l == p2.l && p1.r < p2.r;
}

void sort(pair ps[], int l, int r) {
	if (l >= r)
		return;

	int i = l, j = r;
	pair p = ps[l + rand() % (r-l+1)];

	while (i <= j)
		if (less(ps[i], p))
			i++;
		else if (less(p, ps[j]))
			j--;
		else {
			pair t = ps[i]; ps[i] = ps[j]; ps[j] = t;
			i++; j--;
		}

	sort(i, r); sort(l, j);
}

int main() {
	int n, m;
	
	scanf("%d%d", &n, &m);

	int a[n], c[n+1] = {0};
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if (a[i] <= n)
			c[a[i]]++;
	}

	pair rs[m];
	for (pair *r = rs; r != rs+m; r++)
		scanf("%d%d", &r->l, &r->r);

	sort(rs, 0, m-1);

	return 0;
}
