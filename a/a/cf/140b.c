#include <stdio.h>
#include <string.h>

int main() {
	int n;

	scanf("%d", &n);

	int i, j, a[300][300], b[300];

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
			a[i][j]--;
		}

	for (j = 0; j < n; j++) {
		scanf("%d", &b[j]);
		b[j]--;
	}

	int d[300][300];
	memset(d, 0, sizeof(d));

	int l;
	for (l = 0; l < n; l++) {
		int j = -1, k;

		for (i = 0; i < n; i++) {
			if (i == l)
				continue;

			for (k = 0; k < n; k++)
				if (b[k] == i)
					break;

			if (j == -1) {
				j = k;
				d[l][i] = 1;
			} else {
				if (k < j) {
					j = k;
					d[l][i] = 1;
				}
			}
		}

		/* for (i = 0; i < n; i++)
			printf("%d ", d[l][i]);
		putchar('\n'); */
	}

	int p[300];
	for (i = 0; i < n; i++) {
		j = 0;
		while (j < n && !d[i][a[i][j]])
			j++;

		p[i] = a[i][j];
	}

	for (i = 0; i < n; i++)
		printf("%d ", p[i] + 1);
	putchar('\n');

	return 0;
}
