#include <stdio.h>
#include <string.h>

int zeroless(int a) {
	int b = 0, m = 1;
	while (a != 0) {
		if (a % 10 != 0)
			b += a%10 * m;
		a /= 10;
		m *= 10;
	}

	return b;
}

int main() {
	int a, b;
	scanf("%d%d", &a, &b);

	int c = a + b;

	puts(zeroless(a) + zeroless(b) == zeroless(c) ? "YES" : "NO");

	return 0;
}
