#include <stdio.h>

int main() {
	int x, y, z, k;
	scanf("%d%d%d%d", &x, &y, &z, &k);

	int a = 1, b = 1, c = 1;

	while (a < x && b < y && c < z && k >= 3) {
		a++; b++; c++; k -= 3;
	}

	while (a < x && b < y && k >= 2) {
		a++; b++; k -= 2;
	}

	while (b < y && c < z && k >= 2) {
		b++; c++; k -= 2;
	}

	while (a < x && c < z && k >= 2) {
		a++; c++; k -= 2;
	}

	while (a < x && k > 0) {
		a++; k--;
	}

	while (b < y && k > 0) {
		b++; k--;
	}

	while (c < z && k > 0) {
		c++; k--;
	}

	long long v = 1LL * a * b * c;
	printf("%I64d\n", v);

	return 0;
}
