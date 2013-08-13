#include <stdio.h>
#include <string.h>

int ind (char ch) {
	if ('A' <= ch && ch <= 'Z')
		return ch - 'A';

	return ch - 'a';
}

int main() {
	int n;
	scanf("%d\n", &n);

	int i;
	for (i = 0; i < n; i++) {
		char s[21];
		gets(s);
		// puts(s);

		int li[40] = {2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6,
			7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9};

		int l = 0, r = strlen(s) - 1;
		while (l < r) {
			if (li[ind(s[l])] != li[ind(s[r])])
				break;
			l++; r--;
		}

		if (l < r)
			puts("NO");
		else
			puts("YES");
	}
	return 0;
}
