#include <stdio.h>

int main() {
	int n, m, a;
	scanf("%d%d%d", &n, &m, &a);

	long long nn = n / a;
	if (n % a != 0)
		nn++;

	long long mm = m / a;
	if (m % a != 0)
		mm++;

	printf("%I64d\n", nn*mm);

	return 0;
}
