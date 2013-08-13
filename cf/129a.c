#include <stdio.h>

int main() {
	int n; scanf("%d", &n);

	int a[100], s = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		s += a[i];
	}

	int c = 0;
	for (int i = 0; i < n; i++)
		if ((s - a[i]) % 2 == 0)
			c++;

	printf("%d\n", c);

	return 0;
}
