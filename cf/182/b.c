#include <stdio.h>

int main() {
	int d, n; scanf("%d%d", &d, &n);

	int c = 1;
	long long s = 0;
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);

		if (c != 1)
			s += d+1 - c;
		c = 1 + a;
	}

	printf("%I64d\n", s);

	return 0;
}
