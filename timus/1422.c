#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef __cplusplus
	#include <stdbool.h>
#endif 

typedef struct triple triple;
struct triple { double x, y, z; };

void swap(triple *p, triple *q) {
	triple t = *p; *p = *q; *q = t;
}

bool eq(triple p, triple q) {
	return p.x == q.x && p.y == q.y && p.z == q.z;
}

bool less(triple p, triple q) {
	return p.x < q.x || p.x == q.x && p.y < q.y || p.x == q.x && p.y == q.y && p.z < q.z;
}

double max(double a, double b) {
	return a > b ? a : b;
}

void sort(triple *ts, int l, int r) {
	if (l >= r)
		return;
	
	int i = l, j = r;
	triple t = ts[l + rand() % (r-l+1)];

	while (i <= j)
		if (less(ts[i], t))
			i++;
		else if (less(t, ts[j]))
			j--;
		else {
			swap(&ts[i], &ts[j]);
			i++; j--;
		}
	
	sort(ts, i, r); sort(ts, l, j);
}

int main() {
	int n; scanf("%d", &n);

	if (n == 1) {
		printf("1\n");
		return 0;
	}

	srand(time(NULL));

	triple ps[2000];
	for (triple *p = ps; p != ps+n; p++)
		scanf("%lf%lf%lf", &p->x, &p->y, &p->z);

	int m = 2;
	for (int i = 0; i < n; i++) {
		triple p = ps[i];

		triple ds[2000];
		for (int j = i+1; j < n; j++) {
			triple q = ps[j];
			triple d = {q.x - p.x, q.y - p.y, q.z - p.z};

			if (d.x < 0 || d.x == 0 && d.y < 0 || d.x == 0 && d.y == 0 && d.z < 0)
				d.x = -d.x, d.y = -d.y, d.z = -d.z;

			double m = max(d.x, max(d.y, d.z));
			d.x /= m; d.y /= m; d.z /= m;

			ds[j] = d;
		}

		sort(ds, i+1, n-1);

		int c = 1;
		for (int j = i+2; j < n; j++)
			if (eq(ds[j], ds[j-1])) {
				c++;
			} else {
				if (c + 1 > m)
					m = c + 1;
				c = 1;
			}

		if (c + 1 > m)
			m = c + 1;
	}

	printf("%d\n", m);

	return 0;
}
