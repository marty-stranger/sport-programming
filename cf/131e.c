#include <stdio.h>
#include <string.h>

int x[100000], y[100000];

void sort(int l, int r) {
	if (l >= r)
		return;

	int i = l, j = r, m = (l+r)/2, px = x[m], py = y[m];
	while (i <= j)
		if (x[i] < px || x[i] == px && y[i] < py)
			i++;
		else if (px < x[j] || px == x[j] && py < y[j])
			j--;
		else {
			int t = x[i]; x[i] = x[j]; x[j] = t;
			t = y[i]; y[i] = y[j]; y[j] = t;
			i++; j--;
		}

	sort(i, r); sort(l, j);
}

int main() {
	int n, m; scanf("%d%d", &n, &m);

	int i;
	for (i = 0; i < m; i++) {
		scanf("%d%d", &x[i], &y[i]);
		x[i]--; y[i]--;
	}

	sort(0, m-1);

	int di, c[100000];
	for (di = 0; di < 4; di++) {
		int dx[4] = {1, 0, 1, 1},
			dy[4] = {0, 1, 1, -1};

		int li, h[300000], l[100000], ln[100000];
		memset(h, -1, sizeof(h));
		li = 0;
		for (i = 0; i < m; i++) {
			int j = x[i]*dx[di] + y[i]*dy[di] + (n-1);
			l[li] = i; ln[li] = h[j]; h[j] = li; li++;
		}

		for (i = 0; i < 3*n; i++) {
			int an = 0, a[100000];

			li = h[i];
			while (li != -1) {
				a[an++] = l[li];
				li = ln[li];
			}

			int j;
			for (j = 0; j < an; j++) {
				if (j > 0)
					c[a[j]]++;
				if (j + 1 < an)
					c[a[j]]++;
			}
		}
	}

	int cc[9];
	memset(cc, 0, sizeof(cc));
	for (i = 0; i < m; i++)
		cc[c[i]]++;

	for (i = 0; i < 9; i++)
		printf("%d ", cc[i]);
	putchar('\n');

	return 0;
}
