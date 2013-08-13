#include <math.h>
#include <stdio.h>
#include <string.h>

#ifndef __cplusplus
	#include <stdbool.h>
#endif

typedef struct triple triple;
struct triple { double x, y, z; };

double max(double a, double b) { return a > b ? a : b; }

typedef struct item item;
struct item { triple t; int c; };

#define HT_SIZE 2500
item ht[2*HT_SIZE];

inline int hash(triple t) {
	double h = (t.x * 10000000 + t.y) * 10000000 + t.z;
	h *= 0.6180339887;
	return floor(HT_SIZE * (h - floor(h)));
}

inline bool eq(triple p, triple q) {
	return p.x == q.x && p.y == q.y && p.z == q.z;
}

item *find_or_insert(triple t) {
	int h = hash(t);

	item *i = ht+h;
	while (i->c != 0) {
		if (eq(i->t, t))
			return i;

		i++;
	}

	i->t = t;

	return i;

}

int main() {
	int n; scanf("%d", &n);

	if (n == 1) {
		printf("1\n");
		return 0;
	}

	triple ps[2000];
	for (triple *p = ps; p != ps+n; p++)
		scanf("%lf%lf%lf", &p->x, &p->y, &p->z);

	int m = 1;
	for (int i = 0; i < n; i++) {
		triple p = ps[i];

		memset(ht, 0, sizeof(ht));

		for (int j = i+1; j < n; j++) {
			triple q = ps[j];

			triple d = {q.x - p.x, q.y - p.y, q.z - p.z};
			if (d.x < 0 || d.x == 0 && d.y < 0 || d.x == 0 && d.y == 0 && d.z < 0)
				d.x = -d.x, d.y = -d.y, d.z = -d.z;

			double dm = max(d.x, max(d.y, d.z));
			d.x /= dm; d.y /= dm; d.z /= dm;

			item *i = find_or_insert(d);
			i->c++;
			if (i->c + 1 > m)
				m = i->c + 1;
		}
	}

	printf("%d\n", m);

	return 0;
}


