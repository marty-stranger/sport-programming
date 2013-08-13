#include <stdio.h>
#include <string.h>

char sf[100][10000][101];
char sfi[100][10000][101];

int main() {
	char s[101];

	int rfn = 0;
	char rf[100][100];
	int sfc[100];
	int sfic[100];

	memset(sfc, 0, sizeof(sfc));
	memset(sfic, 0, sizeof(sfic));
	while (gets(s) != NULL) {
		char *t = s;
		while (*t != '\\')
			t++;
		t++;
		while (*t != '\\')
			t++;

		char r[101];
		strncpy(r, s, t - s);
		r[t-s] = '\0';

		int i;
		for (i = 0; i < rfn; i++)
			if (!strcmp(rf[i], r))
				break;

		if (i == rfn) {
			strcpy(rf[i], r);
			rfn++;
		}

		while (1) {
			t++;
			while (*t != '\\' && *t != 0)
				t++;

			if (*t == 0)
				break;

			char p[101];
			strncpy(p, s, t - s);
			p[t-s] = '\0';

			int j;
			for (j = 0; j < sfc[i]; j++)
				if (!strcmp(sf[i][j], p))
					break;

			if (j == sfc[i]) {
				strncpy(sf[i][j], p, t-s);
				p[t-s] = '\0';
				sfc[i]++;
			}
		}

		int j;
		for (j = 0; j < sfic[i]; j++)
			if (!strcmp(sfi[i][j], s))
				break;

		if (j == sfic[i]) {
			strcpy(sfi[i][j], s);
			sfic[i]++;
		}
	}

	int m1 = 0, m2 = 0;
	int i;
	for (i = 0; i < rfn; i++) {
		if (sfc[i] > m1)
			m1 = sfc[i];
		if (sfic[i] > m2)
			m2 = sfic[i];
	}

	printf("%d %d\n", m1, m2);

	return 0;
}
