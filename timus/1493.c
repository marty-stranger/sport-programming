#include <stdio.h>

int sum(int a) {
	return a % 10 + a / 10 % 10 + a / 100 % 10;
}

int check(int a) {
	return sum(a) == sum(a / 1000);
}

int main() {
	int a;
	scanf("%d", &a);

	if (check(a + 1) || check(a - 1))
		puts("Yes");
	else
		puts("No");

	return 0;
}

