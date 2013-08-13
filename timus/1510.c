#include <stdio.h>

int a[500000];

void sort(int l, int r) {
	int i, j, x, t;

	if (l < r) {
		i = l; j = r; x = a[(l + r) / 2];

		while (i <= j)
			if (a[i] < x)
				i++;
			else if (a[j] > x)
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
	int n, i, m, k, r;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);

	sort(0, n-1);

	m = 0;
	k = 1;
	for (i = 1; i < n; i++)
		if (a[i] == a[i-1])
			k++;
		else {
			if (k > m) {
				m = k;
				r = a[i-1];
			}
			k = 1;
		}

	if (k > m) {
		m = k;
		r = a[n - 1];
	}

	printf("%d", r);

	return 0;
}
