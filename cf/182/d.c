#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int main() {
	char s1[100000+1], s2[100000+1];
	scanf("%s%s", s1, s2);

	int s1n = strlen(s1), s2n = strlen(s2);

	int c = 0;
	for (int k = 1; k <= s1n && k <= s2n; k++)
		if (s1n % k == 0 && s2n % k == 0) {
			bool f = true;
			for (int i = 0; i < s1n; i += k)
				if (strncmp(s1, s1+i, k) != 0) {
					f = false;
					break;
				}

			if (!f)
				continue;

			for (int i = 0; i < s2n; i += k)
				if (strncmp(s1, s2+i, k) != 0) {
					f = false;
					break;
				}

			if (f)
				c++;
		}

	printf("%d\n", c);

	return 0;
}
