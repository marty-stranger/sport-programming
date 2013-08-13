#include <stdio.h>
#include <math.h>

# define M_PI		3.14159265358979323846	/* pi */

int main() {
	const double eps = 1e-4;
	double a, b, h;
	int n, i;
	double s, ss;

	scanf("%lf%lf%d", &b, &a, &n);

	a /= 2; b /= 2;

	s = 0;
	for (i = 0; i < n; i++) {
		h = -a + 2 * a * (i + 1) / n;
		ss = M_PI * b * b * h * (1 - h * h / (3 * a * a)); 
		ss += 2 * M_PI * b * b * a / 3;
		printf("%.6lf\n", ss - s);
		s = ss;
	}

	return 0;
}
