#include <ctype.h>
#include <stdio.h>

int main() {
	char c;
	int s = 0;
	while ((c = getchar()) != EOF)
		if (s == 0 && isalpha(c)) 
			putchar(c);
		else if (s == 0 && c == ' ')
			s = 1;
		else if (s == 0 && (c == '.' || c == ',' || c == '?' || c == '!')) {
			s = 2;
			putchar(c);
		} else if (s == 1 && isalpha(c)) {
			putchar(' ');
			putchar(c);
			s = 0;
		} else if (s == 1 && c == ' ')
			;
		else if (s == 1 && (c == '.' || c == ',' || c == '?' || c == '!')) {
			putchar(c);
			s = 2;
		} else if (s == 2 && isalpha(c)) {
			putchar(' ');
			putchar(c);
			s = 0;
		} else if (s == 2 && c == ' ')
			; // nothing
		else if (s == 2 && (c == '.' || c == ',' || c == '?' || c == '!'))
			; // mistake

	return 0;
}
