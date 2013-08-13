#include <stdio.h>

int min(int a, int b) {
	if (a < b)
		return a;
	else
		return b;
}

int main() {
	int x1, x2, y1, y2, n, x, y, s, l, r, m;

	scanf("%d.%d%d.%d%d", &x1, &x2, &y1, &y2, &n);
	x = 10*x1 + x2; y = 10*y1 + y2;


	l = 0;
	r = 10000000;
	while (l < r) {
		m = (l + r) / 2 + 1;
		if (100 * m / n < 10 * x + 5)
			l = m;
		else
			r = m-1;
	}
	s = l;
	s = min(s, 10*n);

	l = 0;
	r = 1000000000;

	while (l < r) {
		m = (l + r) / 2;
		if ((long long)100 * (s + m) / (n + m) >= (long long)10 * y + 5)
			l = m+1;
		else
			r = m;
	}

	printf("%d", l);

	return 0;
}
