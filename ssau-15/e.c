#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct { int c, r, i; } card;

card cs[100000];

int less(card c1, card c2) {
	return c1.c < c2.c || (c1.c == c2.c && c1.r < c2.r);
}

void sort(int l, int r) {
	if (l >= r)
		return;

	int i = l, j = r, m = l + rand()%(r-l+1);
	card p = cs[m];

	while (i <= j)
		if (less(cs[i], p))
			i++;
		else if (less(p, cs[j]))
			j--;
		else {
			card t = cs[i]; cs[i] = cs[j]; cs[j] = t;
			i++; j--;
		}

	sort(l, j); sort(i, r);
}

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d%d", &cs[i].c, &cs[i].r);
		cs[i].i = i;
	}

	sort(0, n - 1);

	int r = 1, i = 0, k = 0;
	int is[100000];

	while (i < n) {
		// printf("r = %d\n", r);
		// printf("next: %d %d\n", cs[i].c, cs[i].r);

		int j = i;
		while (j < n && r >= cs[j].c)
			j++;

		// printf("next j: %d %d\n", cs[j].c, cs[j].r);

		if (r < cs[i].c) 
			break;

		bool f = false;
		for (int ii = i; ii < j; ii++)
			if (cs[ii].i == n-1)
				f = true;

		if (f) {
			is[k++] = n - 1;
			break;
		}

		int mi = i;
		while (i < j) {
			if (cs[i].r > cs[mi].r)
				mi = i;
			i++;
		}

		is[k++] = cs[mi].i;
		r = cs[mi].r;
	}

	if (k == 0 || is[k-1] != n-1) {
		printf("No such luck\n");
		return 0;
	}

	printf("%d\n", k);
	for (int i = 0; i < k; i++) {
		printf("%d", is[i] + 1);
		if (i != k - 1)
			putchar(' ');
	}

	return 0;
}
