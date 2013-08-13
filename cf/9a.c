#include <stdio.h>

int max(int a, int b) { return a > b ? a : b; }

int main() {
	int a, b; scanf("%d%d", &a, &b);

	int c = 6-max(a, b)+1, d = 6;
	if (c % 2 == 0)
		c /= 2, d /= 2;
	if (c % 3 == 0)
		c /= 2, d /= 3;
	printf("%d/%d\n", c, d);

	return 0;
}
