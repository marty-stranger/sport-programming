#include <stdio.h>
#include <string.h>

int min(int a, int b) {
	return a < b ? a : b;
}

int main() {
	int n; scanf("%d", &n);

	int i, c[3];
	memset(c, 0, sizeof(c));
	for (i = 0; i < n; i++) {
		int a; scanf("%d", &a); a--;
		c[a]++;
	}

	printf("%d\n", min(c[0]+c[1], min(c[0]+c[2], c[1]+c[2])));

	return 0;
}
