#include <stdio.h>

int x[100000], h[100000], p[100000];

void swap(int *a, int *b) {
	int t = *a; *a = *b; *b = t;
}

void sort(int l, int r) {
	if (l >= r)
		return;

	int i = l, j = r, pp = x[l + rand() % (r-l+1)];
	while (i <= j)
		if (x[i] < pp)
			i++;
		else if (pp < x[j])
			j--;
		else {
			swap(&x[i], &x[j]);
			swap(&h[i], &h[j]);
			swap(&p[i], &p[j]);
			i++; j--;
		}

	sort(i, r); sort(l, j);
}

int main() {
	int n;
	scanf("%d", &n);

	int i;
	for (i = 0; i < n; i++) {
		scanf("%d%d", &x[i], &h[i]);
		p[i] = i;
	}

	sort(0, n-1);

	int c[100000];
	for (i = n-1; i >= 0; i--) {
		int j = i+1;

		c[p[i]] = 1;
		while (j < n && x[j] < x[i]+h[i]) {
			c[p[i]] += c[p[j]];
			j += c[p[j]];
		}
	}

	for (i = 0; i < n; i++)
		printf("%d ", c[i]);
	putchar('\n');

	return 0;
}
