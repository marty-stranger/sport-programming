#include <math.h>
#include <stdio.h>

int x[100000*4 + 10000], t[100000*4 + 10000], p[100000*4 + 10000];

void swap(int *a, int *b) {
	int t = *a; *a = *b; *b = t;
}

void sort(int l, int r) {
	if (l < r) {
		int i = l, j = r, m = (l + r) / 2, px = x[m], pt = t[m];
		while (i <= j)
			if (x[i] < px || x[i] == px && t[i] < pt)
				i++;
			else if (px < x[j] || px == x[j] && pt < t[j])
				j--;
			else {
				swap(&x[i], &x[j]);
				swap(&t[i], &t[j]);
				swap(&p[i], &p[j]);
				i++; j--;
			}

		sort(i, r); sort(l, j);
	}
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);

	int i, j = 0;
	for (i = 0; i < n; i++) {
		int a, h, l, r;
		scanf("%d%d%d%d", &a, &h, &l, &r);

		x[j] = a - h; t[j] = -1; p[j] = 100 - l; j++;
		x[j] = a - 1; t[j] = 1; p[j] = 100 - l; j++;
		x[j] = a + 1; t[j] = -1; p[j] = 100 - r; j++;
		x[j] = a + h; t[j] = 1; p[j] = 100 - r; j++;
	}

	for (i = 0; i < m; i++) {
		int b, z;
		scanf("%d%d", &b, &z);

		x[j] = b; t[j] = 0; p[j] = z; j++;
	}

	sort(0, 4*n + m - 1);

	double s = 0, pc = 0;
	int z = 0;
	for (i = 0; i < 4*n + m; i++)
		if (t[i] == -1)
			if (p[i] == 0)
				z++;
			else
				pc += log(p[i]) - log(100);
		else if (t[i] == 1)
			if (p[i] == 0)
				z--;
			else
				pc -= log(p[i]) - log(100);
		else
			if (z == 0)
				s += exp(pc) * p[i];

	printf("%.5lf\n", s);

	return 0;
}
