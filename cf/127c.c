#include <math.h>
#include <stdio.h>

int main() {
	int t1, t2, x1, x2, t0; scanf("%d%d%d%d%d", &t1, &t2, &x1, &x2, &t0);

	if (t1 == t2) {
		printf("%d %d\n", x1, x2);
		return 0;
	}

	double d = t2 - t0;
	int z1 = 0, z2 = x2;

	for (int y1 = 1; y1 <= x1; y1++) {
		int y2 = ceil(1.*y1*(t0-t1)/(t2-t0));

		if (y2 > x2)
			continue;

		double t = (1.*t1*y1 + 1.*t2*y2) / (y1+y2);
		double dd = t - t0;
		if (dd < 0)
			continue;

		if (dd < d || fabs(dd-d) <= 1e-9 && y1+y2 > z1+z2) {
			d = dd;
			z1 = y1; z2 = y2;
		}
	}

	printf("%d %d\n", z1, z2);

	return 0;
}
