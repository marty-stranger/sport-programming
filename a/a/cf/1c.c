#include <stdio.h>
#include <math.h>

int main() {
	double x1, y1, x2, y2, x3, y3;
	scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3);

	double a1 = y1-y2, a2 = x2-x1,
	       b1 = y2-y3, b2 = x3-x2,
	       c1 = x3-x1, c2 = y3-y1;

	double s = (a1*c2 - a2*c1) / (a2*b1 - a1*b2);

	double x0 = (x2+x3)/2 + (y2-y3)/2 * s;
	double y0 = (y2+y3)/2 + (x3-x2)/2 * s;

	x1 -= x0; y1 -= y0; x2 -= x0; y2 -= y0; x3 -= x0; y3 -= y0;

	int n;
	for (n = 3; n <= 100; n++) {
		int i, c = 1;
		for (i = 0; i < n; i++) {
			double phi = i*2* M_PI / n;
			double x = x1 * cos(phi) - y1 * sin(phi);
			double y = x1 * sin(phi) + y1 * cos(phi);

			const double eps = 1e-3;
			if (fabs(x-x2) < eps && fabs(y-y2) < eps ||
					fabs(x-x3) < eps && fabs(y-y3) < eps) 
				c++;
		}

		if (c == 3)
			break;
	}

	double rr = x1*x1 + y1*y1;

	printf("%lf\n", n*rr*sin(2*M_PI/n)/2);

	return 0;
}
