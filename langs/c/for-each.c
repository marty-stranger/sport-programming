#include <stdio.h>

int main() {
	int n; scanf("%d", &n);

	int as[n];
	for (int *a = as; a != as+n; ++a)
		scanf("%d", a);

	for (int *a = as; a != as+n; ++a)
		printf("%d ", *a);

	putchar('\n');

	return 0;
}
