#include <stdio.h>

int p(char *s, int n) {
	int i;
	for (i = 0; i < n; i++)
		printf("%s", s);
}

int main() {
	int a, b, c, d;
	scanf("%d%d%d%d", &a, &b, &c, &d);

	int i;
	if (c == d)
		if (a >= c+1 && b >= c) {
			p("4", a - c);
			p("74", c - 1);
			p("7", b - c + 1);
			p("4", 1);
		} else if (a >= c && b >= c + 1) {
			p("7", 1);
			p("4", a - c + 1);
			p("74", c - 1);
			p("7", b - c);
		} else
			printf("%s", "-1");
	else if (c + 1 == d)
		if (a >= c + 1 && b >= c + 1) {
			p("7", 1);
			p("4", a - c);
			p("74", c - 1);
			p("7", b - c);
			p("4", 1);
		} else
			printf("%s", "-1");
 	else if (c == d + 1)
		if (a >= d + 1 && b >= d + 1) {
			p("4", a - d);
			p("7", 1);
			p("47", d - 1);
			p("4", 1);
			p("7", b - d);
		} else
			printf("%s", "-1");
	else
		printf("%s", "-1");

	putchar('\n');

	return 0;
}
