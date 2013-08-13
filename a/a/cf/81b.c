#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main() {
	char s[10000];
	gets(s);

	int i = 0, n = strlen(s);
	while (i < n)
		if (isdigit(s[i])) {
			putchar(s[i]);
			i++;
		} else if (s[i] == ' ') {
			while (s[i] == ' ')
				i++;
			if (isdigit(s[i]))
				putchar(' ');
		} else if (s[i] == ',') {
			putchar(',');
			i++;
			while (s[i] == ' ')
				i++;

			if (i < n && s[i] != '.')
				putchar(' ');
		} else if (s[i] == '.') {
			if (i != 0)
				putchar(' ');
			int j;
			for (j = 0; j < 3; j++) {
				i++;
				putchar('.');
			}

			while (s[i] == ' ')
				i++;
		}

	return 0;
}
