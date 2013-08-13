#include <stdio.h>

int a[100], b[100];

void sort(int l, int r) {
	int m, i, j, k;

	if (l + 1 == r)
		return;

	m = (l + r) / 2;
	sort(l, m);
	sort(m, r);

	i = l; j = m;
	for (k = l; k < r; k++)
		if (i != m && (j == r || j != r && a[i] < a[j])) {
			b[k] = a[i];
			i++;
		} else {
			b[k] = a[j];
			j++;
		}

	for (k = l; k < r; k++)
		a[k] = b[k];
}

int main() {
	int n, i;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);

	sort(0, n);

	for (i = 0; i < n; i++)
		printf("%d\n", a[i]);

	return 0;
}
