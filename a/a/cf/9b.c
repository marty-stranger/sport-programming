#include <math.h>
#include <stdio.h>

double sqr(double a) { return a*a; }

int main() {
	int n, vb, vs; scanf("%d%d%d", &n, &vb, &vs);

	int x[100];
	for (int i = 0; i < n; i++)
		scanf("%d", &x[i]);

	int xu, yu; scanf("%d%d", &xu, &yu);

	double mt, md;
	int mi = 0;
	for (int i = 1; i < n; i++) {
		double d = sqrt(sqr(x[i]-xu)+sqr(yu));
		double t = 1.*x[i]/vb + d/vs;
		if (mi == 0 || t < mt - 1e-9 || fabs(t - mt) <= 1e-9 && d < md)
			mt = t, mi = i, md = d;
	}

	printf("%d\n", mi+1);

	return 0;
}
