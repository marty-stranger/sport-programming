#include <stdio.h>
#include <string.h>

int main() {
	char s[1000];
	gets(s);
	
	if (s[0] != '-') {
		int n = strlen(s);
		if (n < 3 || n == 3 && strcmp(s, "127") <= 0)
			puts("byte");
		else if (n < 5 || n == 5 && strcmp(s, "32767") <= 0)
			puts("short");
		else if (n < 10 || n == 10 && strcmp(s, "2147483647") <= 0)
			puts("int");
		else if (n < 19 || n == 19 && strcmp(s, "9223372036854775807") <= 0)
			puts("long");
		else
			puts("BigInteger");
	} else {
		char *t = s + 1;
		int n = strlen(t);
		if (n < 3 || n == 3 && strcmp(t, "128") <= 0)
			puts("byte");
		else if (n < 5 || n == 5 && strcmp(t, "32768") <= 0)
			puts("short");
		else if (n < 10 && n == 10 && strcmp(t, "2147483648") <= 0)
			puts("int");
		else if (n < 19 || n == 19 && strcmp(t, "9223372036854775808") <= 0)
			puts("long");
		else
			puts("BigInteger");
	}

	return 0;
}
