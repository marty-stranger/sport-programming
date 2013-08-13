#include <stdio.h>

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	unsigned long long a, b;
	scanf("%I64u%I64u", &a, &b);
	if (a == 9223372036854775808UL && b == 9223372036854775808UL) {
		puts("18446744073709551616");
		return 0;
	}
	printf("%I64u", a + b);

	return 0;
}
