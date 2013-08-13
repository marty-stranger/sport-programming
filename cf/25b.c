#include <stdio.h>

int main() {
	int n;
	scanf("%d\n", &n);

	char s[101];
	gets(s);

	int i = 0;
	if (n % 3 == 1) {
		printf("%c%c-%c%c", s[0], s[1], s[2], s[3]);
		i += 4;
	} else if (n % 3 == 2) {
		printf("%c%c", s[0], s[1]);
		i += 2;
	} else {
		printf("%c%c%c", s[0], s[1], s[2]);
		i += 3;
	}

	while (i < n) {
		printf("-%c%c%c", s[i], s[i+1], s[i+2]);
		i += 3;
	}
	putchar('\n');

	return 0;
}
