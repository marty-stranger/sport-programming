#include <stdio.h>
#include <string.h>

int main() {
	int n; scanf("%d\n", &n);

	int i;
	char na[100][11], t[100];
	for (i = 0; i < n; i++) {
		char s[1000];
		gets(s);
		char *ss = s;
		while (*ss != ' ')
			ss++;
		strncpy(na[i], s, ss-s);
		na[i][ss-s] = '\0';

		ss++;
		if (!strcmp(ss, "rat"))
			t[i] = 0;
		else if (!strcmp(ss, "woman") || !strcmp(ss, "child"))
			t[i] = 1;
		else if (!strcmp(ss, "man"))
			t[i] = 2;
		else
			t[i] = 3;
	}

	int j;
	char b[100]; memset(b, 0, sizeof(b));
	for (i = 0; i < n; i++) {
		int mi = -1;
		for (j = 0; j < n; j++)
			if (!b[j])
				if (mi == -1 || t[j] < t[mi])
					mi = j;

		b[mi] = 1;
		puts(na[mi]);
	}

	return 0;
}
