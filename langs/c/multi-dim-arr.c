#include <stdio.h>

int main() {
	int a[1][2][2] = {{{1, 2}, {3, 4}}};

	// int (*b)[2][2] = a; // ok
	// int *b[2][2] - wrong
	// int *b[2] = a[0] // ok
	//

	int i = 5;
	{
		int i = i;
		i++;
		printf("%d\n", i);
		// int (*a)[2] = a[0];
		// printf("%d %d\n", a[1][0], a[1][1]);
	}
	printf("%d\n", i);
}
