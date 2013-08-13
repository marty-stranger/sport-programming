#include <stdio.h>
#include <string.h>

int max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	char a[100001], b[100001];

	gets(a);
	gets(b);

	int i, n = strlen(a);
	int c1 = 0, c2 = 0;
	for (i = 0; i < n; i++)
		if (a[i] == '4' && b[i] == '7')
			c1++;
		else if (a[i] == '7' && b[i] == '4')
			c2++;


	printf("%d\n", max(c1, c2));

	return 0;
}
