#include <stdio.h>
#include <string.h>

int n, a[4*100000];

int count(int ll, int rr) {
	int count_rec(int i, int l, int r) {
		if (rr < l || ll > r)
			return 0;
		if (ll <= l && r <= rr)
			return a[i];

		int m = (l + r) / 2;
		return count_rec(2*i+1, l, m) + count_rec(2*i+2, m+1, r);
	}

	if (ll > rr)
		return 1000000000;

	return count_rec(0, 0, n - 1);
}

void update(int ll, int rr) {
	int update_rec(int i, int l, int r) {
		if (l == r)
			a[i] = 1;
		else {
			int m = (l + r) / 2;
			if (count(ll, m) < m - ll + 1)
				update_rec(2*i+1, l, m);
			else
				update_rec(2*i+2, m+1, r);
			a[i] = a[2*i+1] + a[2*i+2];
		}
	}

	update_rec(0, 0, n - 1);
}

int x[100000], y[100000], p[100000];

int less(int i, int j) {
	return y[i] < y[j] || y[i] == y[j] && x[i] > x[j];
}

void sort(int l, int r) {
	if (l < r) {
		int i = l, j = r, pp = p[(l + r) / 2];
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

int main() {
	int m;
	scanf("%d%d", &n, &m);

	memset(a, 0, sizeof(a));

	int i;
	for (i = 0; i < m; i++) {
		scanf("%d%d", &x[i], &y[i]);
		p[i] = i;
	}

	sort(0, m - 1);

	int c = 0, b[100000];
	for (i = 0; i < m; i++) {
		int j = p[i];
		if (count(n-x[j], y[j]-1) < y[j]+x[j]-n) {
			b[c++] = j;
			update(n-x[j], y[j]-1);
		}
	}

	printf("%d\n", c);
	for (i = 0; i < c; i++)
		printf("%d ", b[i] + 1);
	putchar('\n');

	return 0;
}
