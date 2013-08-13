#include <stdio.h>

int main() {
	int n; scanf("%d", &n);

	int a[1000];
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	int m = a[0], mm = a[0];
	int c1 = 0, c2 = 0;

	for (int i = 1; i < n; i++) {
		if (a[i] > m) {
			m = a[i];
			c1++;
		}

		if (a[i] < mm) {
			mm = a[i];
			c2++;
		}
	}

	printf("%d\n", c1+c2);

	return 0;
}
