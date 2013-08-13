#include <stdio.h>

int main() {
	int n, a, b, c, i, s, k;

	scanf("%d", &n);

	a = b = c = 1;
	for (i = 0; i < n; i++) {
		a = (a * 2) % 10000;
		b = (b * 3) % 10000;
		c = (c * 4) % 10000;
	}

	s = 1 + a + b + c;
	if (s == 0)
		printf("fuck");
	k = 0;
	while (s != 0 && s % 10 == 0) {
		s /= 10;
		k++;
	}

	printf("%d", k);

	return 0;
}
