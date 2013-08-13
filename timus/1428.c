#include <stdio.h>

int main() {
	int a, b, c, i;
	long long d;

	scanf("%d%d%d", &a, &b, &c);

	printf("%I64d\n%I64d\n%d", 1LL << (c - 1) / a, 1LL << (c - 1) / b, 2);
	// printf("%lld\n%lld\n%d", 1LL << (c - 1) / a, 1LL << (c - 1) / b, 2);

	return 0;
}
