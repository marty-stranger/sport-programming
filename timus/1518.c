#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, **t;

void mcopy(int **a, int **b) {
	int i, j; 

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			a[i][j] = b[i][j];
}

void mmake(int ***a) {
	int i;

	*a = (int**)malloc(n * sizeof(int*));
	for (i = 0; i < n; i++)
		(*a)[i] = (int*)malloc(n * sizeof(int));
}

void mset(int **a) {
	int i, j;

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			a[i][j] = 0;

}

void mulmod(int **a, int **b, int p) {
	int i, j, k;
	long long s;

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++) {
			s = 0;
			for (k = 0; k < n; k++)
				s += (long long)a[i][k] * b[k][j] % p;
			t[i][j] = s % p;
		}

	mcopy(a, t);
}

void print(const int **a) {
	int i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			printf("%d ", a[i][j]);
		putchar('\n');
	}
}

int main() {
	int m, p, i, ans, **a, **b, **c, k[100];
	long long s;

	scanf("%d%d%d", &n, &m, &p);
	for (i = 0; i < n; i++)
		scanf("%d", &k[i]);

	mmake(&a); mset(a);

	for (i = 0; i < n; i++)
		scanf("%d", &a[n - 1][i]);
	for (i = 0; i < n - 1; i++)
		a[i][i + 1] = 1;

	
	mmake(&b); mcopy(b, a);
	mmake(&c); mset(c);
	for (i = 0; i < n; i++)
		c[i][i] = 1;

	mmake(&t);
	
	i = m - n;
	while (i != 0)
		if (i % 2 == 0) {
			i /= 2;
			mulmod(b, b, p);
		} else {
			i--;
			mulmod(c, b, p);
		}

	s = 0;
	for (i = 0; i < n; i++)
		s += (long long)c[n - 1][i] * k[i] % p;

	printf("%d", s % p);

	return 0;
}
