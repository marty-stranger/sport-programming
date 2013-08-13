#include <stdio.h>

int main() {
	int n = 90000;

	printf("%d\n", n);
	for (int i = 2; i <= n; i++)
		printf("%d %d\n", i-1, i);

	return 0;
}
