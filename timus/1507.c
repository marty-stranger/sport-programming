#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;

void mult(int **a, int **b, int **c) {
	int i, j, k;

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++) {
			c[i][j] = 0;
			for (k = 0; k < n; k++)
				c[i][j] += a[i][k] * b[k][j];
		}
}

void add(int **a, int **b) {
	int i, j;

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			a[i][j] += b[i][j];
}

void fill(int **a) {
	int i, j;

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			a[i][j] = 0;
}

void cpy(int **a, int **b) {
	int i, j;

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			a[i][j] = b[i][j];
}

int main() {
	int i, j, k, f, **a, **b, **c, **t, **x;

	scanf("%d", &n);

	a = (int**) malloc(n * sizeof(int*));
	b = (int**) malloc(n * sizeof(int*));
	c = (int**) malloc(n * sizeof(int*));
	t = (int**) malloc(n * sizeof(int*));
	x = (int**) malloc(n * sizeof(int*));
	for (i = 0; i < n; i++) {
		a[i] = (int*) malloc(n * sizeof(int));
		b[i] = (int*) malloc(n * sizeof(int));
		c[i] = (int*) malloc(n * sizeof(int));
		t[i] = (int*) malloc(n * sizeof(int));
		x[i] = (int*) malloc(n * sizeof(int));

	}

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			scanf("%d", &a[i][j]);

	fill(c);
	for (i = 0; i < n; i++)
		c[i][i] = 1;

	cpy(x, a);

	k = 2*n - n;
	while (k != 0)
		if (k % 2 == 0) {
			k /= 2;
			mult(x, x, t); cpy(x, t);
		} else {
			k--;
			mult(c, x, t); cpy(c, t);
		}
	
	cpy(b, c);

	for (i = 2*n - n + 1; i <= 2*n + n; i++) {
		mult(c, a, t); cpy(c, t);
		add(b, c);
	}

	f = 1;
	for (i = 0; i < n && f; i++)
		for (j = 0; j < n && f; j++)
			if (b[i][j] == 0)
				f = 0;

	if (f)
		puts("Yes");
	else
		puts("No");

	return 0;
}
