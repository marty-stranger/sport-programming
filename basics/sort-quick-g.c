#include <stdbool.h>
#include <stdio.h>

void sort(int n, bool (*less)(int, int), void (*swap)(int, int)) {
	void rec(int l, int r) {
		if (l >= r)
			return;

		int i = l, j = r, m = (l + r) / 2;
		while (i <= j)
			if (less(i, m))
				i++;
			else if (less(m, j))
				j--;
			else {
				swap(i, j);
				i++; j--;
			}

		rec(l, j); rec(i, r);
	}

	rec(0, n-1);
}

int a[100];

bool less(int i, int j) {
	return a[i] < a[j];
}

void swap(int i, int j) {
	int t = a[i]; a[i] = a[j]; a[j] = t;
}

int main() {
	int n;
	scanf("%d", &n);

	int a[100];
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	sort(n, less, swap);

	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	putchar('\n');

	return 0;
}
