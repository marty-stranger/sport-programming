#include <stdio.h>

int main() {
	// int a, b, c, d; scanf("%d%d%d%d", &a, &b, &c, &d);
	int a, b; scanf("%d%d", &a, &b);

	long long s = 0, i, j;
	for (i = a, j = b; i <= b; i++, j--) {
		int t = i, ss = 0;
		while (t != 0) {
			ss += t % 10;
			t /= 10;
		}

		t = j; int p = 1;
		while (t != 0) {
			p *= t % 10;
			t /= 10;
		}

		s += ss * p;
	}

	printf("%lld\n", s);

	return 0;
}
