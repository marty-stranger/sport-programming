#include <stdio.h>

int main() {
	int k, n, i, j, a[10];

	scanf("%d%d", &k, &n);

	for (i = 0; i < k; i++)
		a[i] = i;

	if (k == n) {
		for (i = 0; i < k; i++)
			printf("%d ", a[i] + 1);
		putchar('\n');
		return 0;
	}

	j = k - 1;
	while (j >= 0) {
		for (i = 0; i < k; i++)
			printf("%d ", a[i] + 1);
		putchar('\n');

		if (a[k - 1] == n - 1)
			j--;
		else
			j = k - 1;

		for (i = k - 1; i >= j; i--)
			a[i] = a[j] + i - j + 1;
	}

	return 0;
}
