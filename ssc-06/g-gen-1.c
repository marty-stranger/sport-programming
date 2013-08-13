#include <stdio.h>

int main() {
	int n = 60001;
	int m = 100000000;

	printf("%d %d %d\n", n - 1, m, m);

	int i;
	for (i = 1; i < n; i++)
		printf("%d %d %d %d\n", m/2/n*i, m/2/n*i, m - m/2/n*i, m - m/2/n*i);
}
