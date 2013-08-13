#include <stdio.h>

int main() {
	int n = 20000;
	printf("%d %d", n, n);

	int i;
	for (i = 0; i < n; i++)
		printf(" %d", i+1);

	return 0;
}
