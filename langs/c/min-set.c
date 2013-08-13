#include <stdio.h>


int main() {
	int a, b;

	a = 3;
	b = 1;

	b <?= a;

	printf("%d\n", b);
}
