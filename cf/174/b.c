#include <stdio.h>
#include <string.h>

int main() {
	char s[4*100000 + 1];
	scanf("%s", s);

	char t[2*4*100000 + 1];
	char *tp = t;

	int i = 0, k = 0;
	while (s[i] != 0) {
		if (i != 0 && s[i] == '.')
			i++;

		int j = i;
		while (s[j] != 0 && s[j] != '.')
			j++;

		int l = j-i;

		if (k == 0)
			if (s[j] == 0) {
				puts("NO");
				return 0;
			} else {
				if (1 <= l && l <= 8) {
					strncpy(tp, s+i, l);
					*(tp+l) = '.';
					tp += l+1;
				} else {
					puts("NO");
					return 0;
				}
			}
		else if (s[j] == 0) {
			if (1 <= l && l <= 3) {
				strncpy(tp, s+i, l);
				*(tp+l) = '\n';
				tp += l+1;
			} else {
				puts("NO");
				return 0;
			}
		} else {
			if (2 <= l && l <= 11) {
				int a, b;
				if (l <= 9) {
					a = 1; b = l-1;
				} else {
					b = 8; a = l-8;
				}

				strncpy(tp, s+i, a);
				*(tp+a) = '\n';
				tp += a+1;

				strncpy(tp, s+i+a, b);
				*(tp+b) = '.';
				tp += b+1;
			} else {
				puts("NO");
				return 0;
			}
		}
		
		i = j;
		k++;
	}

	*tp = '\0';

	puts("YES");
	printf("%s", t);

	return 0;
}
