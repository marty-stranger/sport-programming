#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool check(char *s, int l) {
	printf("l = %d\n", l);
	for (int i = l - 1; i - (l - i) >= 0; i--) {
		printf("l - i = %d\n", l - i);
		puts(s + i);
		puts(s + i - (l - i));
		if (strncmp(s + i, s + i - (l - i), l - i) == 0)
				return false;
	}

	return true;
}

int main() {
	int n = 7;

	char s[n + 1];

	s[0] = 'a';

	for (int i = 1; i <= n; i++) {
		for (char c = 'a'; c <= 'c'; c++) {
			s[i] = c;

			if (!check(s, i + 1))
				continue;
		}
	}

	s[n] = '\0';

	puts(s);

	return 0;
}
