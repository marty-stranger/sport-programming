#include <stdio.h>

int main() {
	int n; scanf("%d", &n);

	int i, s = 0, a[200000];
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		s += a[i];
	}

	int c = 0;
	for (i = 0; i < n; i++)
		if ((s - a[i]) == a[i]*(n-1))
			c++;

	printf("%d\n", c);

	for (i = 0; i < n; i++)
		if ((s - a[i]) == a[i]*(n-1))
			printf("%d\n", i+1);

	return 0;
}
