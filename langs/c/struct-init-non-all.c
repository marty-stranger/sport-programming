#include <stdio.h>

int main() {
	typedef struct { int x, y; } point;

	point a = {1, 2};
	a = (point){.x = 3};

	printf("%d\n", a.y);

	return 0;
}
