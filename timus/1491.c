#include <stdio.h>
#include <string.h>

int main() {
	int n, i, a, b, c, s, d[100001];

	scanf("%d", &n);

	memset(d, 0, sizeof(d));
	scanf("%d%d%d", &a, &b, &c); a--; b--;
	d[a] += c; d[b+1] -= c;

	for (i = 0; i < n; i++) {
		scanf("%d%d%d", &a, &b, &c); a--; b--;
		d[a] += c; d[b+1] -= c;
	}

	s = 0;
	for (i = 0; i < n; i++) {
		s += d[i];
		printf("%d ", s);
	}

	return 0;
}

