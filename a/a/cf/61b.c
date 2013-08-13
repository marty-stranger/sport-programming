#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *clean(char *s) {
	char *ss = (char*) malloc(601);
	char *t = ss;

	while (*s != 0) {
		if ('a' <= *s && *s <= 'z')
			*t++ = *s;
		else if ('A' <= *s && *s <= 'Z')
			*t++ = *s - 'A' + 'a';
		s++;
	}
	*t = 0;

	return ss;
}

int main() {
	char *s[3];
	int i;
	for (i = 0; i < 3; i++) {
		char ss[1000];
		gets(ss);

		s[i] = clean(ss);
		// puts(s[i]);
	}

	// puts("");

	int n;
	scanf("%d\n", &n);

	char c[6][1000];
	memset(c, 0, sizeof(c));
	strcat(c[0], s[0]); strcat(c[0], s[1]); strcat(c[0], s[2]);
	strcat(c[1], s[0]); strcat(c[1], s[2]); strcat(c[1], s[1]);
	strcat(c[2], s[1]); strcat(c[2], s[0]); strcat(c[2], s[2]);
	strcat(c[3], s[1]); strcat(c[3], s[2]); strcat(c[3], s[0]);
	strcat(c[4], s[2]); strcat(c[4], s[0]); strcat(c[4], s[1]);
	strcat(c[5], s[2]); strcat(c[5], s[1]); strcat(c[5], s[0]);

	// for (i = 0; i < 6; i++)
	//	puts(c[i]);

	for (i = 0; i < n; i++) {
		char ss[1000];
		gets(ss);


		char *t = clean(ss);
		int j;
		for (j = 0; j < 6; j++)
			if (!strcmp(c[j], t))
				break;

		if (j == 6)
			puts("WA");
		else
			puts("ACC");
	}

	return 0;
}
