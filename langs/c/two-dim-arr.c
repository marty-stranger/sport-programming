#include <stdio.h>

// http://gcc.gnu.org/onlinedocs/gcc-2.95.3/gcc_4.html#SEC75, 
// gnu c extension, not c++ ?
void print(int m, int n, int a[m][n]) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			printf("%d", a[i][j]);
		putchar('\n');
	}
}

int main() {
	// int m = 2, n = 2;
	int a[2][2] = {{1, 2}, {3, 4}};
	print(2, 2, a);
}
