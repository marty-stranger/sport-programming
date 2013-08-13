#include <stdio.h>

int main() {
	int n, a, b;
	scanf("%d%d%d", &n, &a, &b);

	if (n == 1 && a == 0 && b == 0) {
		puts("1");
		return 0;
	}

	if (a + b == n-1 && b == 0) {
		puts("-1");
		return 0;
	}

	int i;
	if (b == 0 && a < n-1) {
		printf("%d %d ", 1, 1);
		for (i = 0; i < a; i++)
			printf("%d ", i+2);
		for (i = 0; i < n-2-a; i++)
			printf("%d ", 1);
	} else {
		int t = 1;
		for (i = 0; i <= b; i++) {
			printf("%d ", t);
			t *= 2;
		}

		t /= 2;
		for (i = 0; i < a; i++)
			printf("%d " , t + i+1);
		for (i = 0; i < n-a-b-1; i++)
			printf("1 ");
	}

	putchar('\n');

	return 0;
}
