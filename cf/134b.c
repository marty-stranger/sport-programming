#include <stdio.h>

const int inf = 1000000000;

int count(int a, int b) {
	if (b == 0)
		if (a == 1)
			return 0;
		else
			return inf;

	return count(b, a%b) + a/b;
}

int main() {
	int n;
	scanf("%d", &n);

	int i, m = inf;
	for (i = 1; i <= n; i++) {
		int c = count(i, n);
		if (c < m)
			m = c;
	}

	printf("%d\n", m-1);

	return 0;
}
