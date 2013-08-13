#include <stdio.h>
#include <string.h>

int main() {
	char s[2000];
	int n, i, c;

	gets(s);
	c = 0;
	n = strlen(s);
	for (i = 0; i < n; i++) {
		if ('a' <= s[i] && s[i] <= 'z')
			c += (s[i] - 'a') % 3 + 1;
		else if (s[i] == '.')
			c += 1;
		else if (s[i] == ',')
			c += 2;
		else if (s[i] == '!')
			c += 3;
		else if (s[i] == ' ')
			c += 1;
	}

	printf("%d", c);

	return 0;
}
