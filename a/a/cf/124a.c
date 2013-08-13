#include <stdio.h>

int max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	int n, a, b;
	scanf("%d%d%d", &n, &a, &b);

	printf("%d\n", n - max(a+1, n-b) + 1);
	return 0;
}
