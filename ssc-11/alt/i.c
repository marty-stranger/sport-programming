#include <stdio.h>
#include <string.h>

char s[100001];

int main() {
	char l;
	int i, m, c, n;

	gets(s);
	
	m = strlen(s);

	l = 0; n = 0;
	for (i = 0; i < m; i++) {
		c = s[i];
		if (l == 0) {
			if (c == '(') {
				l = '(';
			} else if (c == ')') {
				n++;
			}
		} else if (l == '(') {
			if (c == '(') {
				n++;
			} else if (c == ' ' || 'a' <= c && c <= 'z' || 'A' <= c && c <= 'Z') {

			} else if (c == ')') {
				l = 0;
			} else {
				n++;
				l = 0;
			}
		}
	}

	if (l == '(')
		n++;

	printf("%d\n", n);

	return 0;
}
