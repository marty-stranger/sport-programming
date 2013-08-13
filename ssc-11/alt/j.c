#include <stdio.h>
#include <string.h>

int main() {
	int n, i, j, k, t, u[1000], v[1000], b[1000], bb[1000], l0n, l1n, l1[1000], dn, d[1000],
	    l2n, l2[1000], p[1000];

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &v[i]);
		u[i] = v[i];
	}

	for (i = 0; i < n; i++)
		for (j = i + 1; j < n; j++)
			if (u[j] < u[i])
				t = u[i], u[i] = u[j], u[j] = t;

	memset(b, 0, sizeof(b));

	l0n = 0;
	for (i = 0; i < n; i++)
		if (u[i] == v[i]) {
			b[i] = 1;
			l0n++;
		}

	if (l0n == n) {
		puts("0");
		return 0;
	}

	l1n = 0;
	for (i = 0; i < n; i++) if (!b[i])
		for (j = 0; j < n; j++) if (!b[j])
			if (u[i] == v[j] && v[i] == u[j]) {
				b[i] = b[j] = 1;
				l1[l1n++] = i; l1[l1n++] = j;
				break;
			}

	if (l0n + l1n == n) {
		puts("1");
		printf("%d", l1n / 2);
		for (i = 0; i < l1n; i++)
			printf(" %d", l1[i] + 1);
		putchar('\n');
		return 0;
	}

	memset(bb, 0, sizeof(bb));
	for (i = 0; i < n; i++) if (!b[i])
		for (j = 0; j < n; j++) if (!b[j] && !bb[j])
			if (u[j] == v[i]) {
				bb[j] = 1;
				p[i] = j;
				break;
			}

	l2n = 0;
	for (i = 0; i < n; i++) if (!b[i]) {
		dn = 0;

		d[dn++] = j = i;
		b[i] = 1;
		while (v[j] != u[i]) {
			j = p[j];
			b[j] = 1;
			d[dn++] = j;
		}

		j = dn-1; k = 1;
		while (j > k) {
			l1[l1n++] = d[j]; l1[l1n++] = d[k];
			j--; k++;
		}

		l2[l2n++] = d[0]; l2[l2n++] = d[1];
		j = dn-1; k = 2;
		while (j > k) {
			l2[l2n++] = d[j]; l2[l2n++] = d[k];
			j--; k++;
		}
	}

	puts("2");

	printf("%d", l1n / 2);
	for (i = 0; i < l1n; i++)
		printf(" %d", l1[i] + 1);
	putchar('\n');

	printf("%d", l2n / 2);
	for (i = 0; i < l2n; i++)
		printf(" %d", l2[i] + 1);
	putchar('\n');

	return 0;
}
