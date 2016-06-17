#include <stdio.h>

int a[100000];

void sort(int l, int r) {
	if (l < r) {
		int i = l, j = r, p = a[(l + r) / 2];
		while (i <= j)
			if (a[i] < p)
				i++;
			else if (a[j] > p)
				j--;
			else {
				int t = a[i]; a[i] = a[j]; a[j] = t;
				i++; j--;
			}

		sort(i, r); sort(l, j);
	}
}

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	sort(0, n - 1);

	int i = n - 1;
	while (i >= 0 && a[i] > i)
		i--;

	printf("%d\n", i + 1);

	return 0;
}
