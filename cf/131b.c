#include <stdio.h>
#include <string.h>

int main() {
	int n;
	scanf("%d", &n);

	int i, c[21], a[100000];
	memset(c, 0, sizeof(c));
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		c[a[i] + 10]++;
	}

	long long r = 0;
	for (i = 0; i < n; i++)
		if (a[i] == 0)
			r += c[0 + 10]-1;
		else
			r += c[-a[i] + 10];

	printf("%I64d\n", r/2);

	return 0;
}
