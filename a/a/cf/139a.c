#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);


	int i, a[7];
	for (i = 0; i < 7; i++)
		scanf("%d", &a[i]);

	i = 0;
	while (n > a[i]) {
		n -= a[i];
		i = (i + 1) % 7;
	}

	printf("%d\n", i + 1);

	return 0;
}
