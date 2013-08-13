#include <stdio.h>

#define mn 1000000

char s[1000001];
int n, c4[4*mn], c7[4*mn], c47[4*mn], c74[4*mn], sw[4*mn];

int max(int a, int b) {
	return a > b ? a : b;
}

void set(int i) {
	int l = 2*i+1, r=2*i+2;
	c4[i] = c4[l] + c4[r];
	c7[i] = c7[l] + c7[r];
	c47[i] = max(c4[l] + c47[r], c47[l] + c7[r]);
	c74[i] = max(c7[l] + c74[r], c74[l] + c4[r]);
}

void build(int i, int l, int r) {
	sw[i] = 0;
	if (l == r) {
		c4[i] = s[l] == '4';
		c7[i] = s[l] == '7';
		c47[i] = c74[i] = 1;
	} else {
		int m = (l + r) / 2;
		build(2*i+1, l, m);
		build(2*i+2, m+1, r);
		set(i);
	}
}

void swap(int *a, int *b) {
	int t = *a; *a = *b; *b = t;
}

void tree_switch(int i) {
	sw[i] = !sw[i];
	swap(&c4[i], &c7[i]);
	swap(&c47[i], &c74[i]);
}

void update(int ll, int rr) {
	void update_rec(int i, int l, int r) {
		if (rr < l || r < ll)
			return;
		if (ll <= l && r <= rr) {
			tree_switch(i);
		} else {
			if (sw[i]) {
				tree_switch(2*i+1);
				tree_switch(2*i+2);
				sw[i] = 0;
			}

			int m = (l + r) / 2;
			update_rec(2*i+1, l, m);
			update_rec(2*i+2, m+1, r);
			set(i);
		}
	}

	update_rec(0, 0, n-1);
}

int main() {
	int m;
	scanf("%d%d\n", &n, &m);

	gets(s);

	build(0, 0, n - 1);

	int i;
	for (i = 0; i < m; i++) {
		char c[20];
		scanf("%s", c);
		if (c[0] == 's') {
			int l, r;
			scanf("%d%d", &l, &r);
			l--; r--;
			update(l, r);
		} else {
			printf("%d\n", c47[0]);
		}

		scanf("\n");
	}

	return 0;
}
