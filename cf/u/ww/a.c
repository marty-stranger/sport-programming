#include <stdio.h>

int main() {
	int n, x, y; scanf("%d%d%d", &n, &x, &y);

	for (int a = 0; a <= 2000000; a++)
		if (1ll*100*(x+a) >= 1ll*y*n) {
			printf("%d\n", a);
			break;
		}

	return 0;
}
