#include <stdio.h>

const int mod = 1000000000 + 7;

inline int sum(int a, int b) {
	int s = a + b;
	if (s >= mod)
		s -= mod;
	return s;
}

int main() {
	int n; scanf("%d", &n);

	int a = 0, b = 0, c = 0, d = 1;

	for (int i = 0; i < n; i++) {
		int aa = sum(sum(b, c), d), bb = sum(sum(a, c), d),
		    cc = sum(sum(a, b), d), dd = sum(sum(a, b), c);
		a = aa; b = bb; c = cc; d = dd;
	}
	
	printf("%d\n", d);

	return 0;
}
