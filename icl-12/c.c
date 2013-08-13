#include <math.h>
#include <stdio.h>

double x[1000], y[1000];

void sort(int l, int r) {
	if (l >= r)
		return;

	int i = l, j = r, m = (l+r) / 2;
	double px = x[m], py = y[m];
	while (i <= j)
		if (x[i] < px || x[i] == px && y[i] < py)
			i++;
		else if (px < x[j] || px == x[j] && py < y[j])
			j--;
		else {
			double t = x[i]; x[i] = x[j]; x[j] = t;
			t = y[i]; y[i] = y[j]; y[j] = t;
			i++; j--;
		}

	sort(i, r); sort(l, j);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	const double eps = 1e-9;
	int n; scanf("%d", &n);

	int i, m = 0, cnt = 1;
	double a[1000], b[1000], c[1000];
	for (i = 0; i < n; i++) {
		int ang1, ang2; scanf("%d%d", &ang1, &ang2);
		double ang1_rad = 2*M_PI*ang1/360, ang2_rad = 2*M_PI*ang2/360;
		double x1 = cos(ang1_rad), y1 = sin(ang1_rad),
		       x2 = cos(ang2_rad), y2 = sin(ang2_rad);

		a[i] = y1-y2; b[i] = x2-x1; c[i] = x1*y2-x2*y1;

		cnt++;

		int j, k = 0;
		for (j = 0; j < i; j++) {
			double d = a[i]*b[j] - a[j]*b[i];
			x[k] = - (c[i]*b[j] - c[j]*b[i]) / d;
			y[k] = - (a[i]*c[j] - a[j]*c[i]) / d;

			if (x[k]*x[k] + y[k]*y[k] < 1.0 - eps)
				k++;
		}

		sort(0, k-1);

		for (j = 0; j < k; j++)
			if (j == 0 || !(fabs(x[j] - x[j-1]) < eps && fabs(y[j] - y[j-1]) < eps))
				cnt++;
	}
	
	printf("%d\n", cnt);

	return 0;
}
