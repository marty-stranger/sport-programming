#include <stdio.h>

int main() {
	long long q;
	scanf("%I64d", &q);

	long long i, p1 = 0, p2 = 0;
	for (i = 2; i*i <= q; i++)
		if (q % i == 0) {
			q /= i;
			p1 = i;
			break;
		}

	for (i = 2; i*i <= q; i++)
		if (q % i == 0) {
			q /= i;
			p2 = i;
			break;
		}

	if (p1 == 0)
		puts("1\n0");
	else if (p2 == 0)
		puts("2");
	else
		printf("1\n%I64d\n", p1*p2);

	return 0;
}
