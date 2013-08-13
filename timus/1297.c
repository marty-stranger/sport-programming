#include <stdio.h>
#include <string.h>

int main() {
	char s[1001], ss[1001];
	int n, i, d, md, mi, b1[1000], b2[1000], bb[1000];

	gets(s); n = strlen(s);
	for (i = 0; i < n; i++)
		b1[i] = b2[i] = 1;

	md = 1; mi = 0;
	for (d = 2; d <= n; d++) {
		memset(bb, 0, sizeof(bb));
		for (i = 0; i < n - d + 1; i++)
			if (s[i] == s[i + d - 1] && b1[i + 1]) {
				bb[i] = 1;
				if (md != d) {
					md = d;
					mi = i;
				}
			}
		memcpy(b1, b2, sizeof(b1));
		memcpy(b2, bb, sizeof(bb));
	}

	strncpy(ss, s + mi, md); ss[md] = '\0';
	puts(ss);

	return 0;
}
