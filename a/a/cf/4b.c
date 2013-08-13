#include <stdio.h>

int main() {
	int d, s; scanf("%d%d", &d, &s);

	int mins[d], maxs[d], s1 = 0, s2 = 0;
	for (int i = 0; i < d; i++) {
		scanf("%d%d", &mins[i], &maxs[i]);
		s1 += mins[i];
		s2 += maxs[i];
	}

	if (s < s1 || s > s2) {
		puts("NO");
		return 0;
	}

	int a[d];
	for (int i = 0; i < d; i++) {
		a[i] = mins[i];
		s -= mins[i];
	}

	while (s > 0) {
		for (int i = 0; i < d; i++)
			if (s > 0 && a[i] + 1 <= maxs[i]) {
				a[i]++;
				s--;
			}
	}

	puts("YES");
	for (int i = 0; i < d; i++)
		printf("%d ", a[i]);
	putchar('\n');

	return 0;
}
