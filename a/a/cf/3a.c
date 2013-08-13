#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
	return a > b ? a : b;
}

void read(int *x, int *y) {
	char s[3];
	gets(s);
	*x = s[0]-'a';
	*y = s[1]-'1';
}

int main() {
	int x1, y1, x2, y2;
	read(&x1, &y1); read(&x2, &y2);

	printf("%d\n", max(abs(x2-x1), abs(y2-y1)));
	while (x1 != x2 || y1 != y2) {
		if (x1 < x2)
			x1++, putchar('R');
		else if (x1 > x2)
			x1--, putchar('L');
		if (y1 < y2)
			y1++, putchar('U');
		else if (y1 > y2)
			y1--, putchar('D');
		putchar('\n');
	}

	return 0;
}
