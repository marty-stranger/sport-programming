#include <stdio.h>
#include <string.h>

int min(int a, int b) {
	return a < b ? a : b;
}

int main() {
	int n; scanf("%d", &n);

	int i, c[3];
	memset(c, 0, sizeof(c));
	for (i = 0; i < n; i++) {
		int a; scanf("%d", &a);

		int s = 0;
		while (a != 0) {
			s += a % 10;
			a /= 10;
		}

		c[s % 3]++;
	}

	printf("%d\n", c[0] / 2 + min(c[1], c[2]));

	return 0;
}
