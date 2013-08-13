#include <stdio.h>

int main() {
	int n, x; scanf("%d%d", &n, &x);

	int a[500*5];
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	for (int i = 0; i < n; i++)
		for (int j = i+1; j < n; j++)
			if (a[j] < a[i]) {
				int t = a[j]; a[j] = a[i]; a[i] = t;
			}

	int l = -1;
	for (int i = 0; i < n; i++)
		if (a[i] == x)
			l = i;

	int k = 0;
	if (l == -1) {
		int i = 0;
		while (i < n && a[i] < x)
			i++;

		l = i;
		for (int i = n-1; i >= l; i--)
			a[i+1] = a[i];

		a[l] = x;
		n++; k++;
	}

	while (a[(n+1)/2 - 1] != x) {
		// printf("l = %d\n", l);

		l++;
		for (int i = n-1; i >= l; i--)
			a[i+1] = a[i];
		a[l] = x;
		n++; k++;

		/* for (int i = 0; i < n; i++)
			printf("%d ", a[i]);
		putchar('\n'); */
	}

	printf("%d\n", k);

	return 0;
}
