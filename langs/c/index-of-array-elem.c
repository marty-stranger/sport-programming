#include <stdio.h>

typedef struct { int x, y; } point;

int main() {
	point ps[] = {{1, 1}, {2, 2}, {3, 3}};

	point *p = &ps[4];

	printf("%d\n", p - ps);

	return 0;
}
