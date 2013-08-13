#include <stdio.h>
#include <string.h>

int main() {
	int n;
	scanf("%d\n", &n);

	int i;

	char *s1 = NULL, *s2 = NULL;
	int c1 = 0, c2 = 0;
	for (i = 0; i < n; i++) {
		char s[20];
		gets(s);

		if (s1 == NULL) {
			s1 = strdup(s);
			c1++;
		} else if (!strcmp(s1, s))
			c1++;
		else if (s2 == NULL) {
			s2 = strdup(s);
			c2++;
		}  else if (!strcmp(s2, s))
			c2++;
	}

	if (c1 > c2)
		puts(s1);
	else
		puts(s2);

	return 0;
}
