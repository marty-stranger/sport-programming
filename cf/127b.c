#include <stdio.h>

int main() {
	int n; scanf("%d", &n);

	int c[101] = {0};
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		c[a]++;
	}

	int t = 0;
	for (int i = 1; i <= 100; i++)
		t += c[i]/2;

	printf("%d\n", t/2);

	return 0;
}
