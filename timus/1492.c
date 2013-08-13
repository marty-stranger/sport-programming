#include <stdio.h>
#include <string.h>

const double eps = 1e-4;

double online(double x1, double y1, double x2, double y2, double x3, double y3) {
	double sm = (x2 - x1)*(y3 - y1) - (x3 - x1)*(y2 - y1);
	return -eps < sm && sm < eps;
}

double h[30001], xe[30001], xo[30001], ye[30001], yo[30001];

int main() {
	int n, i, f, x, y, px, py, j, ne, no, b[30001];

	memset(b, 0, sizeof(b));
	scanf("%d", &n);

	f = 1;
	scanf("%d%d", &x, &y);
	b[x + 15000] = 1;
	h[x + 15000] = y;
	px = x;
	py = y;
	for (i = 1; i < n && f; i++) {
		scanf("%d%d", &x, &y);
		for (j = px + 1; j < x; j++)
			h[j + 15000] = (double)(y - py) * (j - px) / (x - px) + py;
		b[x + 15000] = 1;
		h[x + 15000] = y;
		px = x;
		py = y;
	}

	/*if (n == 3) {
		puts("No");
		return 0;
	}*/
		//return x / (x - x);
	puts("Yes");

	ne = no = 0;
	for (x = -15000; x <= 15000; x++)
		if (b[x + 15000] || b[-x + 15000]) {
			xe[ne] = x;
			ye[ne] = (h[x + 15000] + h[-x + 15000]) / 2;
			ne++;
		}
	for (x = -15000; x <= 15000; x++)
		if (b[x + 15000] || b[-x + 15000]) {
			xo[no] = x;
			yo[no] = (h[x + 15000] - h[-x + 15000]) / 2;
			no++;
		}

	for (i = 0; i < ne; i++)
		if (!(i > 0 && i < ne-1 && online(xe[i-1], ye[i-1], xe[i], ye[i], xe[i+1], ye[i+1])))
			printf("%.4lf %.4lf\n", xe[i], ye[i]);
	for (i = 0; i < no; i++)
		if (!(i > 0 && i < no-1 && online(xo[i-1], yo[i-1], xo[i], yo[i], xo[i+1], yo[i+1])))
			printf("%.4lf %.4lf\n", xo[i], yo[i]);

	return 0;
}

