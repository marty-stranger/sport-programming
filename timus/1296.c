#include <stdio.h>

int max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	int n, a, i, c, m;

	scanf("%d", &n);

	c = m = 0;
	for (i = 0; i < n; i++) {
		scanf("%d", &a);
		c = max(c + a, 0);
		m = max(m, c);
	}

	printf("%d", m);

	return 0;
}
