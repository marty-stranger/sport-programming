#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);

	int i;
	int n1, n2, c1 = 0, c2 = 0;
	for (i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		if (a % 2 == 0) {
			n1 = i;
			c1++;
		} else {
			n2 = i;
			c2++;
		}
	}

	if (c1 == 1)
		printf("%d\n", n1 + 1);
	else
		printf("%d\n", n2 + 1);

	return 0;
}
