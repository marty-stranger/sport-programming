#include <stdio.h>

int main() {
	char s[101];
	gets(s);

	char *t = s;
	t++;

	int y = 1;
	while (*t != 0) {
		if ('a' <= *t && *t <= 'z') {
			y = 0;
			break;
		}
		t++;
	}

	if (y) {
		t = s;
		while (*t != 0) {
			if ('a' <= *t && *t <= 'z')
				putchar(*t - 'a' + 'A');
			else
				putchar(*t - 'A' + 'a');
			t++;
		}
	} else
		puts(s);

	return 0;
}
