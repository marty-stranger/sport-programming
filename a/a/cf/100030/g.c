#include <stdio.h>

typedef struct { int c, i; } pair;

pair ps[2000];

void sort(int l, int r) {
	if (l < r) {
		int i = l, j = r, m = (l+r)/2;
		int p = ps[m].c;

		while (i <= j)
			if (ps[i].c < p)
				i++;
			else if (ps[j].c > p)
				j--;
			else {
				pair t = ps[i]; ps[i] = ps[j]; ps[j] = t;
				i++; j--;
			}

		sort(i, r); sort(l, j);
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int k, n; scanf("%d%d", &k, &n);

	for (int i = 0; i < n; i++) {
		int c; scanf("%d", &c);
		ps[i] = (pair){c, i};
	}

	sort(0, n-1);

	int a[2000] = {0};

	for (int i = 0; i < n; i++) {
		if (k > ps[i].c) {
			k -= ps[i].c;
			a[ps[i].i] = ps[i].c;
		} else {
			a[ps[i].i] = k;
			k = 0;
		}
	}

	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	putchar('\n');

	return 0;
}
