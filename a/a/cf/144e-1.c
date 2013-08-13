#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int x[100000], y[100000], p[100000];

int less(int i, int j) {
	return y[i] < y[j] || y[i] == y[j] && x[i] < x[j];
}

void sort(int l, int r) {
	if (l < r) {
		int i = l, j = r, pp = p[l + rand() % (r-l+1)];
		while (i <= j)
			if (less(p[i], pp))
				i++;
			else if (less(pp, p[j]))
				j--;
			else {
				int t = p[i]; p[i] = p[j]; p[j] = t;
				i++; j--;
			}

		sort(i, r); sort(l, j);
	}
}

int nx[100001];

int find(int i) {
	if (nx[i] == i)
		return i;
	return nx[i] = find(nx[i]);
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);

	int i;
	for (i = 0; i < m; i++) {
		scanf("%d%d", &x[i], &y[i]);
		x[i]--; y[i]--;
		x[i] = n-1-x[i];
		p[i] = i;
	}

	sort(0, m-1);

	for (i = 0; i <= n; i++)
		nx[i] = i;

	int c = 0, b[100000];
	for (i = 0; i < m; i++) {
		int j = p[i];

		int k = find(x[j]);
		if (k <= y[j]) {
			b[c++] = j;
			nx[k] = k+1;
		}
	}

	printf("%d\n", c);
	for (i = 0; i < c; i++)
		printf("%d ", b[i] + 1);
	putchar('\n');

	return 0;
}
