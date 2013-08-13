#include <stdio.h>

int n, c = 0;

void go(int i, int a) {
	if (i == 10) {
		if (a <= n)
			c++;
		return;
	}

	go(i+1, a*10 + 1);
	go(i+1, a*10);
}


int main() {
	scanf("%d", &n);
	go(0, 0);

	printf("%d\n", c-1);

	return 0;
}
