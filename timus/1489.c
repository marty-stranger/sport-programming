#include <math.h>
#include <stdio.h>

int a, b, c;

double convert(double x, double y, double *xxx, double *yyy, double *zzz) {
	double xx, yy, zz;

	if (0 <= y && y < b) {
		x -= c;
		xx = c; yy = x; zz = y;
	} else if (b <= y && y < b + c) {
		x -= c; y -= b;
		xx = c - y; yy = x; zz = b;
	} else if (0 <= x && x < c && b + c <= y && y <= b + c + b) {
		y -= b + c;
		xx = c - x; yy = 0; zz = b - y;
	} else if (c <= x && x < c + a && b + c <= y && y < b + c + b) {
		x -= c; y -= b + c;
		xx = 0; yy = x; zz = b - y;
	} else if (c + a <= x && x <= c + a + c && b + c <= y && y <= b + c + b) {
		x -= c + a; y -= b + c;
		xx = x; yy = a; zz = b - y;
	} else if (b + c + b <= y && y <= b + c + b + c) {
		x -= c; y -= b + c + b;
		xx = y; yy = x; zz = 0;
	}
	*xxx = xx; *yyy = yy; *zzz = zz;
}

int main() {
	double x1, y1, x2, y2, xx1, yy1, xx2, yy2, zz1, zz2;

	scanf("%d%d%d%lf%lf%lf%lf", &a, &b, &c, &x1, &y1, &x2, &y2);

	convert(x1, y1, &xx1, &yy1, &zz1);
	convert(x2, y2, &xx2, &yy2, &zz2);

	printf("%lf", sqrt((xx1 - xx2)*(xx1 - xx2) + (yy1 - yy2)*(yy1 - yy2) + (zz1 - zz2)*(zz1 - zz2)));

	return 0;
}

