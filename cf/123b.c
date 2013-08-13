#include <stdio.h>

int abs(int a) {
	return a > 0 ? a : -a;
}

int ceili(int a, int b) {
	int c;
	if (a > 0) {
		c = a / b;
	} else {
		c = a / b;
		c--;
	}

	return c;
}

int max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	int a, b, x1, y1, x2, y2;

	scanf("%d%d%d%d%d%d", &a, &b, &x1, &y1, &x2, &y2);

	int xx = ceili(x1+y1, 2*a), yy = ceili(x1-y1, 2*b);
	int xxx = ceili(x2+y2, 2*a), yyy = ceili(x2-y2, 2*b);

	printf("%d\n", max(abs(xx-xxx), abs(yy-yyy)));

	return 0;
}
