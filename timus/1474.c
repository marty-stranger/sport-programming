#include <stdio.h>

int main() {
	int n, d, a, s, i;

	scanf("%d", &n);

	a = n-1;

	printf("%d\n", (n+1)*(n+1)-1);

	s = 1;
	for (d = 2; d <= n+1; d++) {
		for (i = 0; i < d; i++) {
			printf("%d ", a);
			a += 2*s;
		}

		a -= 2*s;
		a += s;		
		s = -s;
	}

	a += 2*s;
	for (d = n; d >= 1; d--) {
		for (i = 0; i < d; i++) {
			printf("%d ", a);
			a += 2*s;
		}

		a -= 2*s;
		a -= s;
		s = -s;
	}

	return 0;
}
