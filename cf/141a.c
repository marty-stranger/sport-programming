#include <stdio.h>
#include <string.h>

int main() {
	int a[100];
	memset(a, 0, sizeof(a));

	char s[101];
	gets(s);

	int i, l = strlen(s);
	for (i = 0; i < l; i++)
		a[s[i] - 'A']--;

	gets(s);
	l = strlen(s);
	for (i = 0; i < l; i++)
		a[s[i] - 'A']--;

	gets(s);
	l = strlen(s);
	for (i = 0; i < l; i++)
		a[s[i] - 'A']++;

	for (i = 0; i < 'Z' - 'A'; i++)
		if (a[i] != 0) {
			puts("NO");
			return 0;
		}

	puts("YES");
	return 0;
}
