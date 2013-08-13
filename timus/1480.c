/*acc*/
#include <stdio.h>

int main() {
	int n, i, j, k, a[50][50];

	scanf("%d", &n);

	k = 0;	
	for (i = 0; i < n; i++) {
		j = !(i % 2);
		while (j < n) {
			a[i][j] = k;
			j += 2;
			k++;
		}
	}

	k = n*n-1;	
	for (i = 0; i < n; i++) {
		j = i % 2;
		while (j < n) {
			a[i][j] = k;
			j += 2;
			k--;
		}
	}

	printf("%d\n", n*n + n/2 + 1);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			printf("%d ", a[i][j] + 1);
		putchar('\n');
	}

	return 0;
}

