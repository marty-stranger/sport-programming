#include <stdio.h>

int main() {
	int a, n;
	scanf("%d%d", &a, &n);

	int r = 1;
	while (n) {
		if (n & 1)
			r *= a;
		a *= a;
		n >>= 1;
	}

	printf("%d\n", r);
}
