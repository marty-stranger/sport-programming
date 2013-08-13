#include <stdio.h>
#include <math.h>

double dist(double x1, double y1, double x2, double y2) {
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int main() {
	double xx, yy, x[200], y[200];
	int n = 0;

	while (scanf("%lf%lf", &xx, &yy) == 2) {
		x[n] = xx; y[n] = yy; n++;
	}

	int m = 1;
	double r = 2.5;
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if (j != i && dist(x[i], y[i], x[j], y[j]) <= 5*5 + 1e-9) {
				double d = dist(x[i], y[i], x[j], y[j]);
				double ds = sqrt(d);
				double h = sqrt(r*r - d / 4 + 1e-9);

				int s;
				for (s = -1; s <= 1; s += 2) {
					double xx = (x[i] + x[j]) / 2 + s * h * (y[i] - y[j]) / ds;
					double yy = (y[i] + y[j]) / 2 + s * h * (x[j] - x[i]) / ds;

					int k, c = 2;
					for (k = 0; k < n; k++) if (k != i && k != j)
						if (dist(xx, yy, x[k], y[k]) <= r*r + 1e-9)
							c++;

					if (c > m)
						m = c;
				}
			}

	printf("%d\n", m);

	return 0;
}
