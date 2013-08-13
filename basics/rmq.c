#include <stdio.h>
#include <string.h>

int n, a[10000], t[40000];

void build(int i, int l, int r) {
	if (l == r)
		t[i] = a[l];
	else {
		int m = (l + r) / 2;
		build(2*i+1, l, m);
		build(2*i+2, m+1, r);
		t[i] = t[2*i+1] + t[2*i+2];
	}
}

int range(int ll, int rr) {
	int range_rec(int i, int l, int r) {
		if (rr < l || ll > r)
			return 0;
		if (ll <= l && r <= rr)
			return t[i];

		int m = (l + r) / 2;
		return range_rec(2*i+1, l, m) + range_rec(2*i+2, m+1, r);
	}

	return range_rec(0, 0, n-1);
}

void update(int ii, int v) {
	void update_rec(int i, int l, int r) {
		if (l == r)
			t[i] = v;
		else {
			int m = (l + r) / 2;
			if (ii <= m)
				update_rec(2*i+1, l, m);
			else
				update_rec(2*i+2, m+1, r);
			t[i] = t[2*i+1] + t[2*i+2];
		}
	}

	update_rec(0, 0, n-1);
}

void print() {
	void print_rec(int i, int l, int r) {
		printf("[%d,%d] = %d\n", l+1, r+1, t[i]);

		if (l != r) {
			int m = (l + r) / 2;
			print_rec(2*i+1, l, m);
			print_rec(2*i+2, m+1, r);
		}
	}

	print_rec(0, 0, n-1);
}

int main() {
	n = 5;
	
	memset(a, 0, sizeof(a));

	build(0, 0, n-1);

	while (1) {
		char c;
		scanf("%c", &c);

		switch (c) {
		case 'u':
			{
				int i, v;
				scanf("%d%d", &i, &v);
				i--;
				update(i, v);
			}
			break;
		case 'r':
			{
				int l, r;
				scanf("%d%d", &l, &r);
				l--; r--;
				printf("range: %d\n", range(l, r));
			}
			break;
		case 'p':
			print();
		}
	}

	return 0;
}
