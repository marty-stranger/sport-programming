#include <stdio.h>
#include <string.h>

int a[1000000], b[1<<22];

const int m = 22;

void print(int a) {
	for (int i = m-1; i >= 0; i--)
		putchar(((a>>i)&1) + '0');
}

void fill(int a, int c) {
	if (b[c] != -1)
		return;

	b[c] = a;

	for (int i = 0; i < m; i++) {
		int cc = c & ~(1 << i);
		if (cc != c) {
			// printf("c = "); print(c);
			// printf(" c' = "); print(cc);
			// putchar('\n');
			fill(a, cc);
		}
	}
}

int main() {
	int n; scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	memset(b, -1, sizeof(b));
	for (int i = 0; i < n; i++) {
		int aa = (~a[i])&((1<<m)-1);
		/* printf("%d -> ", a[i]);
		print(aa);
		putchar('\n'); */
		fill(a[i], aa);
	}

	for (int i = 0; i < n; i++)
		printf("%d ", b[a[i]]);
	putchar('\n');

	return 0;
}
