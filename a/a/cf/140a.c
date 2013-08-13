#include <stdio.h>
#include <math.h>

int main() {
	int n, R, r;
	scanf("%d%d%d", &n, &R, &r);

	if (R < r)
		puts("NO");
	else if (2*r > R)
		if (n == 1)
			puts("YES");
		else
			puts("NO");
	else if (2*r == R)
		if (n == 1 || n == 2)
			puts("YES");
		else
			puts("NO");
	else {
		double a = 2*asin(1. * r / (R - r));

		if (n*a <= 2*M_PI + 1e-9)
			puts("YES");
		else
			puts("NO");
	}

	return 0;
}
