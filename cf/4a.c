#include <stdio.h>

int main() {
	int a; scanf("%d", &a);

	if (a > 2 && a % 2 == 0)
		puts("YES");
	else
		puts("NO");

	return 0;
}
