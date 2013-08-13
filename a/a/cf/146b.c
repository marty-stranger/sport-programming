#include <stdio.h>

int main() {
	int a, b;
	scanf("%d%d", &a, &b);

	while (1) {
		a++;

		int d = a, c = 0;
		int m = 1;
		while (d != 0) {
			if (d % 10 == 4 || d % 10 == 7) {
				c += m * (d % 10);
				m *= 10;
			}
			d /= 10;
		}

		if (c == b)
			break;
	}

	printf("%d\n", a);

	return 0;
}
