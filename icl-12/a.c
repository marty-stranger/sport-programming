#include <stdio.h>
#include <string.h>

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, k;
	scanf("%d%d", &n, &k);

	char b[20000];
	memset(b, 0, sizeof(b));

	int i;
	for (i = 0; i < k; i++) {
		int j; scanf("%d", &j); j--;
		b[j] = 1;
	}

	char c[20000];
	memset(c, 0, sizeof(c));

	for (i = 0; i < n; i++)
		if (c[i] != b[i]) {
			b[i] = c[i];
			int j;
			for (j = i+1; j-1 < n; j += i+1)
				c[j-1] = !c[j-1];
			printf("%d ", i+1);
		}

	return 0;
}
