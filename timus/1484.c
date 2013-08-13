#include <math.h>
#include <stdio.h>

int min(int a, int b) {
	if (a < b)
		return a;
	else
		return b;
}

int main() {
	const double eps = 1e-8;
	int x1, x2, y1, y2, n, x, y, s, l, r, m;

	scanf("%d.%d%d.%d%d", &x1, &x2, &y1, &y2, &n);
	x = 10*x1 + x2; y = 10*y1 + y2;

	s = floor(((double)10*x + 5) * n / 100 - eps);
	s = min(s, 10*n);

	if (100*s < (10*y + 5) * n)
		putchar('0');
	else
		printf("%d", (int)ceil(((double)100*s - (10*y + 5 - eps)*n) / (10*y + 5 - 100 - eps)));

	return 0;
}
