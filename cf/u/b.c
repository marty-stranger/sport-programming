#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct { int c, t, i; } item;

item a[1000];

item r[1000][1000];

void sort(int l, int r) {
	if (l >= r)
		return;

	int i = l, j = r, m = l + rand()%(r-l+1);
	int p = a[m].c;

	while (i <= j)
		if (a[i].c < p)
			i++;
		else if (a[j].c > p)
			j--;
		else {
			item t = a[i]; a[i] = a[j]; a[j] = t;
			i++; j--;
		}

	sort(i, r); sort(l, j);
}

int main() {
	int n, k; scanf("%d%d", &n, &k);

	for (int i = 0; i < n; i++) {
		int c, t; scanf("%d%d", &c, &t);
		a[i] = (item){c, t, i};
	}

	sort(0, n-1);

	int c[1000]; int d[1000];
	memset(c, 0, sizeof(c));
	memset(d, 0, sizeof(d));

	int j = k-1;
	for (int i = n-1; i >= 0; i--)
		if (a[i].t == 1) {
			r[j][c[j]++] = a[i];
			d[j] = 1;
			if (j > 0)
				j--;
		}

	for (int i = 0; i < n; i++)
		if (a[i].t == 2) {
			r[j][c[j]++] = a[i];
			if (j > 0)
				j--;
		}

	double s = 0;
	for (int i = 0; i < k; i++) {
		int min = -1; long long ss = 0;
		for (int j = 0; j < c[i]; j++) {
			if (min == -1 || r[i][j].c < min)
				min = r[i][j].c;
			ss += r[i][j].c;
		}

		ss -= min;
	        if (d[i])
			s += ss + 1.*min/2;
		else
			s += ss + min;
		// printf("! d[i] = %d\n", d[i]);
	}

	printf("%.1lf\n", s);

	for (int i = 0; i < k; i++) {
		printf("%d", c[i]);
		for (int j = 0; j < c[i]; j++)
			printf(" %d", r[i][j].i+1);
		putchar('\n');
	}

	return 0;
}
