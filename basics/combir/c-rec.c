#include <stdio.h>

int n = 9, k = 10, c[10];


void print() {
	int i;

	for (i = 0; i < n; i++)
		printf("%d ", c[i] + 1);
	printf("\n");
}

int f(int n, int k) {
	int i;

	if (n == 0) {
		print();
		return;
	}

	for (i = k - 1; i >= n - 1; i--) {
		c[n - 1] = i;
		f(n - 1, i);
	}
}

int main() {
	f(n, k);

	return 0;
}
