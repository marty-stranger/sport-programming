#include <stdio.h>

int main() {
	long long n;

	scanf("%I64d", &n);

	printf("%I64d", n*(n + 1) * (n + 2) / 2);

	return 0;
}
