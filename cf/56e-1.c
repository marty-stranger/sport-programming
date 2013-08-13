#include <stdio.h>
#include <string.h>

int n, x[100000], h[100000], p[100000];

void sort(int l, int r) {
	if (l < r) {
		int i = l, j = r, px = x[l + rand() % (r-l+1)];
		while (i <= j)
			if (x[i] < px)
				i++;
			else if (x[j] > px)
				j--;
			else {
				int t = x[i]; x[i] = x[j]; x[j] = t;
				t = h[i]; h[i] = h[j]; h[j] = t;
				t = p[i]; p[i] = p[j]; p[j] = t;
				i++; j--;
			}

		sort(i, r); sort(l, j);
	}
}

int t[4*100000], ti[4*100000];

int max(int a, int b) {
	return a > b ? a : b;
}

void build(int i, int l, int r) {
	if (l == r) {
		t[i] = x[l]+h[l];
		ti[i] = l;
	} else {
		int m = (l+r)/2;
		build(i+i+1, l, m);
		build(i+i+2, m+1, r);

		if (t[i+i+1] > t[i+i+2]) {
			t[i] = t[i+i+1];
			ti[i] = ti[i+i+1];
		} else {
			t[i] = t[i+i+2];
			ti[i] = ti[i+i+2];
		}
	}
}

const int inf = 1000000000;

struct pair { int v, i; };

int range(int ll, int rr) {
	struct pair range_rec(int i, int l, int r) {
		if (ll > r || rr < l) {
			struct pair p = {-inf, 0};
			return p;
		}
		if (ll <= l && r <= rr) {
			struct pair p = {t[i], ti[i]};
			return p;
		}

		int m = (l + r) / 2;
		struct pair p1 = range_rec(i+i+1, l, m);
		struct pair p2 = range_rec(i+i+2, m+1, r);
		if (p1.v > p2.v)
			return p1;
		else
			return p2;
	}

	return range_rec(0, 0, n-1).i;
}

int main() {
	scanf("%d", &n);

	int i;
	for (i = 0; i < n; i++) {
		scanf("%d%d", &x[i], &h[i]);
		p[i] = i;
	}

	sort(0, n-1);
	
	build(0, 0, n - 1);

	int c[100000];
	for (i = n-1; i >= 0; i--) {
		// printf("i = %d %d %d\n", i+1, x[i], h[i]);

		int l = i, r = n-1;
		while (l < r) {
			int m = (l+r+1)/2;
			if (x[m] <= x[i]+h[i]-1)
				l = m;
			else
				r = m-1;
		}

		// printf("l = %d r = %d\n", l+1, r+1);

		// printf("i = %d l = %d\n", i+1, l+1);
		int j = range(i, l);

		// printf("j = %d\n", j);

		if (j == i)
			if (l == i)
				c[p[i]] = 1;
			else
				c[p[i]] = l-i + c[p[l]];
		else
			c[p[i]] = j-i + c[p[j]];
	}

	for (i = 0; i < n; i++)
		printf("%d ", c[i]);
	putchar('\n');

	return 0;
}
