#include <stdio.h>
#include <string.h>

typedef struct { int i, c; } value;

int less(value a, value b) {
	return a.c < b.c;
}

struct { int n; value a[50000]; } h;

void insert(value v) {
	int i = h.n, j = (i-1)/2;

	while (i != 0 && less(v, h.a[j])) {
		h.a[i] = h.a[j];
		i = j; j = (i-1)/2;
	}
	h.a[i] = v;
	h.n++;
}

void down(int i) {
	value v = h.a[i];
	while (1) {
		int j = 2*i+1;
		if (j >= h.n)
			break;

		if (j+1 < h.n && less(h.a[j+1], h.a[j]))
			j++;

		if (!less(h.a[j], v))
			break;

		h.a[i] = h.a[j];
		i = j;
	}

	h.a[i] = v;
}

value extract() {
	value v = h.a[0];
	h.a[0] = h.a[h.n-1];
	h.n--;

	if (h.n != 0)
		down(0);

	return v;
}

int main() {
	char p[50001]; gets(p);
	int n = strlen(p);

	int d = 0;
	long long c = 0;
	for (int i = 0; i < n; i++) {
		if (p[i] == '(')
			d++;
		else if (p[i] == ')')
			d--;
		else {
			int a, b; scanf("%d%d", &a, &b);

			p[i] = ')';
			c += b;
			insert((value){i, a-b});
			d--;
		}

		if (d < 0) {
			if (h.n == 0) {
				puts("-1");
				return 0;
			}

			value v = extract();
			d += 2;
			p[v.i] = '(';
			c += v.c;
		}
	}

	if (d != 0) {
		puts("-1");
		return 0;
	}

	printf("%I64d\n", c);
	puts(p);

	return 0;
}
