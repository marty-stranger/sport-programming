#include <stdio.h>

int main() {
	int n;
	scanf("%d\n", &n);

	char a[51];
	gets(a);

	int i;
	for (i = 0; i < n; i++)
		if (a[i] != '7' && a[i] != '4') {
			puts("NO");
			return 0;
		}

	int s1 = 0, s2 = 0, l = 0, r = n-1;

	while (l < r) {
		s1 += a[l]; s2 += a[r];
		l++; r--;
	}

	if (s1 != s2) {
		puts("NO");
		return 0;
	}

	puts("YES");
	return 0;
}
