#include <stdio.h>

int check1(int a, int b, int c) {
	return a + b > c && a + c > b && c + b > a;
}

int check2(int a, int b, int c) {
	return a + b >= c && a + c >= b && c + b >= a;
}

int main() {
	int a, b, c, d; scanf("%d%d%d%d", &a, &b, &c, &d);
	if (check1(a, b, c) || check1(a, b, d) || check1(a, c, d) ||
			check1(b, c, d))
		puts("TRIANGLE");
	else if (check2(a, b, c) || check2(a, b, d) || check2(a, c, d) ||
		                        check2(b, c, d))
		puts("SEGMENT");
	else
		puts("IMPOSSIBLE");

	return 0;
}
