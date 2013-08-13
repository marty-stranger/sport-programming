#include <stdio.h>
#include <stdlib.h>

typedef struct { int p, i; } boat;

int less(boat a, boat b) {
	return a.p > b.p;
}

void sort(boat b[], int l, int r) {
	if (l >= r)
		return;

	int i = l, j = r, m = l + rand() % (r-l);
	boat p = b[m];

	while (i <= j)
		if (less(b[i], p))
			i++;
		else if (less(p, b[j]))
			j--;
		else {
			boat t = b[i]; b[i] = b[j]; b[j] = t;
			i++; j--;
		}

	sort(b, l, j); sort(b, i, r);
}

int main() {
	int n, v; scanf("%d%d", &n, &v);

	int n1 = 0, n2 = 0;
	boat b1[n], b2[n];
	for (int i = 0; i < n; i++) {
		int t, p; scanf("%d%d", &t, &p);

		if (t == 1)
			b1[n1++] = (boat){p, i};
		else
			b2[n2++] = (boat){p, i};
	}

	sort(b1, 0, n1-1);
	sort(b2, 0, n2-1);

	int i = 0, s1 = 0;
	while (i < n1 && v >= 1) {
		s1 += b1[i].p;
		v--;
		i++;
	}

	int j = 0, s2 = 0;
	while (j < n2 && v >= 2) {
		s2 += b2[j].p;
		v -= 2;
		j++;
	}

	int m = s1+s2, mi = i, mj = j;
	while (j < n2 && i >= 1) {
		s1 -= b1[i-1].p;
		i--;
		v++;

		if (v >= 2) {
			s2 += b2[j].p;
			j++;
			v -= 2;
		}

		if (s1+s2 > m)
			m = s1+s2, mi = i, mj = j;
	}

	printf("%d\n", m);
	for (int i = 0; i < mi; i++)
		printf("%d ", b1[i].i+1);
	for (int i = 0; i < mj; i++)
		printf("%d ", b2[i].i+1);
	putchar('\n');
}
