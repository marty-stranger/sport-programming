#include <math.h>
#include <stdio.h>

double sqr(double a) {
	return a*a;
}

double x[3], y[3], r[3];

double f(double x0, double y0) {
	double a[3];
	for (int i = 0; i < 3; i++)
		a[i] = sqrt(sqr(x[i]-x0) + sqr(y[i]-y0)) / r[i];

	double r = 0;
	for (int i = 0; i < 3; i++)
		r += sqr(a[i] - a[(i+1)%3]);
	// XXX replace of sqr to fabs -> fails on #13

	return r;
}

int main() {
	double x0 = 0, y0 = 0;
	for (int i = 0; i < 3; i++) {
		scanf("%lf%lf%lf", &x[i], &y[i], &r[i]);
		x0 += x[i]; y0 += y[i];
	}

	x0 /= 3; y0 /= 3;

	const double eps = 1e-5;
	double d = 1;
	while (d > eps) {
		int ok = 0;
		// printf("x = %lf y = %lf -> %lf\n", x0, y0, f(x0, y0));
		if (f(x0+d, y0) < f(x0, y0))
			x0 += d, ok = 1;
		else if (f(x0-d, y0) < f(x0, y0))
			x0 -= d, ok = 1;

		if (f(x0, y0+d) < f(x0, y0))
			y0 += d, ok = 1;
		else if (f(x0, y0-d) < f(x0, y0))
			y0 -= d, ok = 1;

		if (!ok)
			d *= .5;
	}

	if (f(x0, y0) < eps)
		printf("%lf %lf\n", x0, y0);

	return 0;
}
