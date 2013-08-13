#include <stdio.h>
#include <string.h>

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, k; scanf("%d%d", &n, &k);

	n--;
	int c = 0; long long t = k;
	while (n > 0) {
		if (n > t) {
			n -= t;
			t += t*k;
		} else {
			n = 0;
			t += n*k;
		}
		c++;
	}

	printf("%d\n", c);

	return 0;
}
