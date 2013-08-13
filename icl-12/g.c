#include <stdio.h>

int swap(int *a, int *b) {
	int t = *a; *a = *b; *b = t;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n; scanf("%d", &n);

	int a[100][100];
	int i, j, p[100];
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			scanf("%d", &a[i][j]);
		p[i] = i;
	}

	int k;
	for (k = 0; k < 1000; k++) {
		for (i = 0; i < n-1; i++)
			if (a[i][i+1] == 0) {
				for (j = 0; j < n; j++)
					if (j != i && j != i+1) {
						swap(&a[i][j], &a[i+1][j]);
						swap(&a[j][i], &a[j][i+1]);
					}
				swap(&a[i][i+1], &a[i+1][i]);
				swap(&p[i], &p[i+1]);

				/* for (i = 0; i < n; i++) {
					for (j = 0; j < n; j++)
						printf("%d ", a[i][j]);
					putchar('\n');
				}
				putchar('\n'); */
			}
	}

	for (i = 0; i < n; i++)
		printf("%d ", p[i] + 1);
	putchar('\n');

	return 0;
}
