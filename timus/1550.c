#include <math.h>
#include <stdio.h>

#define M_PI 3.14159265358979323846

double max(double a, double b) {
	return a > b ? a : b;
}

int main() {
	double w, h, x, y, r, d, m;

	scanf("%lf%lf%lf%lf%lf", &h, &w, &x, &y, &r);

	d = w - 2 * max(fabs(x), fabs(y));
	m = h*d / w;
	printf("%lf", w*w*h / 3 - M_PI*r*r*m);
	
	return 0;
}
