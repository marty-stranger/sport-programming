#include <stdio.h>
#include <string.h>

int main() {
	char s[201];
	gets(s);

	int i, n = strlen(s), c[200];
	memset(c, 0, sizeof(c));
	for (i = 0; i < n; i++)
		if (s[i] != ' ')
			c[s[i]]++;

	gets(s);

	n = strlen(s);
	for (i = 0; i < n; i++)
		if (s[i] != ' ') {
			c[s[i]]--;
			if (c[s[i]] < 0)
				break;
		}

	if (i == n)
		puts("YES");
	else
		puts("NO");
}
