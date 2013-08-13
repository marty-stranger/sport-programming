#include <ctype.h>
#include <stdio.h>

int main() {
	int n;
	scanf("%d\n", &n);

	int i;
	for (i = 0; i < n; i++) {
		char s[100];
		gets(s);

		int j = 0;
		while (!isdigit(s[j]))
			j++;
		while (s[j] != '\0' && isdigit(s[j]))
			j++;

		if (s[j] != '\0') {
			char s1[100];
			int j = 1;
			while (isdigit(s[j])) {
				s1[j-1] = s[j];
				j++;
			}
			s1[j-1] = '\0';

			j++;
			int a;
			sscanf(s + j, "%d", &a);

			char s2[100];
			int s2n = 0;
			while (a != 0) {
				s2[s2n++] = 'A' + ((a - 1) % 26);
				a = (a - 1) / 26;
			}
			s2[s2n] = '\0';

			for (j = 0; j < s2n / 2; j++) {
				char c = s2[j]; s2[j] = s2[s2n-1-j]; s2[s2n-1-j] = c;
			}

			printf("%s%s\n", s2, s1);
		} else {
			char s1[100];
			int a = 0, j = 0, m = 1;
			while (!isdigit(s[j])) {
				a = a * 26 + (s[j] - 'A' + 1);
				j++;
			}

			printf("R%sC%d\n", s + j, a);
		}
	}

	return 0;
}
