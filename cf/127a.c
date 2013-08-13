#include <math.h>
#include <stdio.h>

int main() {
	int n, k; scanf("%d%d", &n, &k);

	double l = 0;
	double x, y; scanf("%lf%lf", &x, &y);
	for (int i = 1; i < n; i++) {
		double xx, yy; scanf("%lf%lf", &xx, &yy);

		l += sqrt((xx-x)*(xx-x) + (yy-y)*(yy-y));
		x = xx; y = yy;
	}

	printf("%.7lf\n", k*l/50);

	return 0;
}
