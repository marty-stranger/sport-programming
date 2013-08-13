#include <stdio.h>

int n, a[2*100000];

int sum(int l, int r) {
	l += n; r += n;

	int s = 0;
	while (l <= r) {
		if (l & 1) {
			s += a[l];
			l++;
		}
		if (!(r & 1)) {
			s += a[r];
			r--;
		}

		l /= 2; r /= 2;
	}

	return s;
}

void set(int i) {
	a[i/2] = a[i] + a[i^1];
}

void update(int i, int v) {
	i += n;

	a[i] = v;

	while (i > 1) {
		set(i);
		i /= 2;
	}
}

void print() {
	for (int *v = a; v != a+2*n; v++)
		printf("%d ", *v);
	putchar('\n');
}

int main() {
	scanf("%d", &n);

	for (int *v = a+n; v != a+2*n; v++)
		scanf("%d", v);

	for (int i = 2*n-1; i > 1; i -= 2)
		set(i);

	for (;;) {
		char c[100]; scanf("%s", c);
		switch (c[0]) {
			int i, j, v;

			case 'u':
				scanf("%d%d", &i, &v); i--;
				update(i, v);
				break;
			case 'q':
				scanf("%d%d", &i, &j); i--; j--;
				printf("%d\n", sum(i, j));
				break;
			case 'p':
				print();
				break;
		}
	}

	return 0;
}
