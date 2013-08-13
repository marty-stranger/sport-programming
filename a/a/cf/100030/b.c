#include <stdio.h>

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n; scanf("%d", &n);

	int s = 0;
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		s += a-1;
	}

	if (s % 2 == 1)
		puts("Constantine");
	else
		puts("Mike");

	return 0;
}
