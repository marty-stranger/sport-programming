#include <stdio.h>

int main() {
	int n, k; scanf("%d%d", &n, &k);

	int i, a[100];
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);

	int c = 0;
	while (1) {
		i = 0;
		int y = 0;
		while (i < n) {
			while (i + 1 < n && a[i+1] == a[i])
				i++;

			if (a[i] < k) {
				a[i]++;
				y = 1;
			}

			i++;
		}

		/* for (i = 0; i < n; i++)
			printf("%d ", a[i]);
		putchar('\n'); */

		if (!y)
			break;
		c++;
	}

	printf("%d\n", c);

	return 0;
}
