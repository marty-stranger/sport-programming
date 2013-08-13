#include <stdio.h>

int main() {
	int i;
	for (i = 1; i <= 100; i++) {
		int a = rand() % 1000000000,
			b = rand() % 1000000000;

		if (a <= b)
			printf("%d %d\n", a, b);
		else
			printf("%d %d\n", b, a);
	}

	return 0;
}
