#include <stdio.h>

void s(int n, int a[]) {
	void f(int l, int r) {
		if (l >= r)
			return;

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

		f(l, j); f(i, r);
	}

	f(0, n-1);
}

int main() {
	int n;
	scanf("%d", &n);

	int a[100];
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	s(n, a);

	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	putchar('\n');

	return 0;
}
