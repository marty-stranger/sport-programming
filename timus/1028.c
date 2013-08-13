#include <stdio.h>
#include <stdlib.h>

int n, m, k, x[15000], y[15000], xx[15000], xi[32001], d[30000], l[30000], r[30000], c[15000];

void sort(int l, int r) {
	int i, j, e, t;
	
	if (l < r) {
		i = l; j = r; e = xx[(l + r) / 2];
		while (i <= j)
			if (xx[i] < e)
				i++;
			else if (xx[j] > e)
				j--;
			else {
				t = xx[i]; xx[i] = xx[j]; xx[j] = t;
				i++; j--;
			}

		sort(l, j);
		sort(i, r);
	}
}

void build(int p, int i, int j) {
	if (i < j) {
		d[k] = 0;
		l[p] = k;
		k++;
		build(k-1, i, (i+j)/2);

		d[k] = 0;
		r[p] = k;
		k++;
		build(k-1, (i+j)/2+1, j);
	} else if (i == j) {
		d[k] = 0;
		l[p] = -1;
		r[p] = -1;
	}
}

void update(int nx, int p, int i, int j) {
	if (p != -1 && xx[i] <= nx && nx <= xx[j]) {
		d[p]++;
		update(nx, l[p], i, (i+j)/2);
		update(nx, r[p], (i+j)/2+1, j);
	}
}

int count(int i, int j, int p, int ii, int jj) {
	if (p != -1) {
		if (ii > j || jj < i)
			return 0;
		if (i <= ii && jj <= j)
			return d[p];
		else
			return count(i, j, l[p], ii, (ii+jj)/2) + count(i, j, r[p], (ii+jj)/2+1, jj);

	} else
		return 0;
}

int main() {
	int i, j;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d%d", &x[i], &y[i]);
		xx[i] = x[i];
	}

	sort(0, n-1);
	m = 1;
	for (i = 1; i < n; i++)
		if (xx[i] != xx[i-1]) {
			xx[m] = xx[i];
			xi[xx[m]] = m;
			m++;
		}

	k = 1; d[0] = 0;
	build(0, 0, m-1);

	memset(c, 0, sizeof(c));

	for (i = 0; i < n; i++) {
		c[count(0, xi[x[i]], 0, 0, m-1)]++;
		update(x[i], 0, 0, m-1);
	}

	for (i = 0; i < n; i++)
		printf("%d\n", c[i]);
	
	return 0;
}

