#include <stdio.h>

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, m; scanf("%d%d", &n, &m);

	long long bs[n];
	for (int i = 0; i < n; i++) {
		bs[i] = 0;

		int k; scanf("%d", &k);
		for (int j = 0; j < k; j++) {
			int a; scanf("%d", &a); a--;
			bs[i] |= 1ll<<a;
		}
	}

	int min = 1e9, mini;
	for (int i = 0; i < 1<<n; i++) {
		int c = 0;
		long long b = 0;
		for (int j = 0; j < n; j++)
			if ((i & (1<<j)) != 0) {
				c++;
				b |= bs[j];
			}
		// printf("i = %d c = %d\n", i, c);

		if (b == (1ll<<m)-1 && c < min) {
			min = c;
			mini = i;
		}
	}

	printf("%d\n", min);
	for (int i = 0; i < n; i++)
		if ((mini & (1<<i)) != 0)
			printf("%d ", i+1);
	putchar('\n');

	return 0;
}
