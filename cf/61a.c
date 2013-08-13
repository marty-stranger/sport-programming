#include <stdio.h>
#include <string.h>

int main() {
	char s[101]; gets(s);
	char t[101]; gets(t);

	int i, n = strlen(s);
	for (i = 0; i < n; i++)
		putchar(s[i] != t[i] ? '1' : '0');

	return 0;
}
