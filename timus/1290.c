#include <stdio.h>
#include <stdlib.h>

int a[25000];

void sort(int l, int r) {
	int i, j, m, t;

	if (l < r) {
		i = l; j = r; m = a[l + rand() % (r - l + 1)];

		while (i <= j)
			if (a[i] > m)
				i++;
			else if (a[j] < m)
				j--;
			else {
				t = a[i]; a[i] = a[j]; a[j] = t;
				i++; j--;
			}

		sort(i, r);
		sort(l, j);
	}
}

int main() {
	int n, i;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);

	sort(0, n - 1);

	for (i = 0; i < n; i++)
		printf("%d\n", a[i]);

	return 0;
}
