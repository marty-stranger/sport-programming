#include <stdio.h>
#include <stdlib.h>
#include <string.h>

inline void swap(int *a, int *b) {
	int t = *a; *a = *b; *b = t;
}

int sx[2*60000+2], sy1[2*60000+2], sy2[2*60000+2], sri[2*60000+2];

void sort1(int l, int r) {
	if (l < r) {
		int i = l, j = r, m = l + rand() % (r - l), px = sx[m], py = sy1[m];
		while (i <= j)
			if (sx[i] < px || sx[i] == px && sy1[i] < py)
				i++;
			else if (px < sx[j] || px == sx[j] && py < sy1[j])
				j--;
			else {
				swap(&sx[i], &sx[j]);
				swap(&sy1[i], &sy1[j]);
				swap(&sy2[i], &sy2[j]);
				swap(&sri[i], &sri[j]);
				i++; j--;
			}

		sort1(i, r); sort1(l, j);
	}
}

int troot = -1, tf = 0, tk[2*60000+2], tv[2*60000+2], tc[2*60000+2], tl[2*60000+2], tr[2*60000+2];

int find_i(int k) {
	int i = troot;

	while (i != -1 && tk[i] != k)
		if (k < tk[i])
			i = tl[i];
		else
			i = tr[i];

	return i;
}

inline int rotate_left(int i) {
	int j = tr[i]; tr[i] = tl[j]; tl[j] = i;
	tc[j] = tc[i]; tc[i] = 1;
	return j;
}

inline int rotate_right(int i) {
	int j = tl[i]; tl[i] = tr[j]; tr[j] = i;
	tc[j] = tc[i]; tc[i] = 1;
	return j;
}

inline void flip_colors(int i) {
	tc[i] = !tc[i]; tc[tl[i]] = !tc[tl[i]]; tc[tr[i]] = !tc[tr[i]];
}

inline int is_red(int i) {
	return i != -1 && tc[i] == 1;
}

inline int fix_up(int i) {
	if (is_red(tr[i]))
		i = rotate_left(i);

	if (is_red(tl[i]) && is_red(tl[tl[i]]))
		i = rotate_right(i);

	if (is_red(tl[i]) && is_red(tr[i]))
		flip_colors(i);

	return i;
}

void insert(int k, int v) {
	int insert_rec(int i) {
		if (i == -1) {
			i = tf; tf++;
			tk[i] = k; tv[i] = v;
			tl[i] = tr[i] = -1;
			tc[i] = 1;
			return i;
		}

		if (k < tk[i])
			tl[i] = insert_rec(tl[i]);
		else
			tr[i] = insert_rec(tr[i]);

		return fix_up(i);
	}

	troot = insert_rec(troot);
	tc[troot] = 0;
}

inline int move_red_left(int i) {
	flip_colors(i);

	if (is_red(tl[tr[i]])) {
		tr[i] = rotate_right(tr[i]);
		i = rotate_left(i);
		flip_colors(i);
	}

	return i;
}

inline int move_red_right(int i) {
	flip_colors(i);

	if (is_red(tl[tl[i]])) {
		i = rotate_right(i);
		flip_colors(i);
	}

	return i;
}

inline int min_i(int i) {
	while (tl[i] != -1)
		i = tl[i];
	return i;
}

int delete_min_rec(int i) {
	if (tl[i] == -1)
		return -1;

	if (!is_red(tl[i]) && !is_red(tl[tl[i]]))
		i = move_red_left(i);

	tl[i] = delete_min_rec(tl[i]);

	return fix_up(i);
}

void delete(int k) {
	int delete_rec(int i) {
		if (k < tk[i]) {
			if (!is_red(tl[i]) && !is_red(tl[tl[i]]))
				i = move_red_left(i);
			tl[i] = delete_rec(tl[i]);
		} else {
			if (is_red(tl[i]))
				i = rotate_right(i);

			if (k == tk[i] && tr[i] == -1)
				return -1;

			if (!is_red(tr[i]) && !is_red(tl[tr[i]]))
				i = move_red_right(i);

			if (k == tk[i]) {
				int j = min_i(tr[i]);
				tk[i] = tk[j]; tv[i] = tv[j];
				tr[i] = delete_min_rec(tr[i]);
			} else
				tr[i] = delete_rec(tr[i]);
		}

		return fix_up(i);
	}

	troot = delete_rec(troot);
	tc[troot] = 0;
}

int succ_i(int k) {
	int i = troot, j;

	while (i != -1 && tk[i] != k) {
		if (k < tk[i]) {
			j = i;
			i = tl[i];
		} else
			i = tr[i];
	}

	if (tr[i] == -1)
		return j;

	i = tr[i];
	while (tl[i] != -1)
		i = tl[i];
	return i;
}

long long sa[60001];

void sort2(int l, int r) {
	if (l < r) {
		int i = l, j = r;
	      	long long p = sa[l + rand() % (r - l)];
		while (i <= j)
			if (sa[i] < p)
				i++;
			else if (p < sa[j])
				j--;
			else {
				long long t = sa[i]; sa[i] = sa[j]; sa[j] = t;
				i++; j--;
			}

		sort2(i, r); sort2(l, j);
	}
}

int main() {
	int n, x, y;
	scanf("%d%d%d", &n, &x, &y);

	int si = 0;
	sx[si] = 0; sy1[si] = 0; sy2[si] = y; sri[si] = 0; si++;
	sx[si] = x; sy1[si] = 0; sy2[si] = y; sri[si] = 0; si++;

	long long a[60001];
	a[0] = 1LL * x * y;

	int i;
	for (i = 0; i < n; i++) {
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		if (x1 > x2)
			swap(&x1, &x2);
		if (y1 > y2)
			swap(&y1, &y2);

		sx[si] = x1; sy1[si] = y1; sy2[si] = y2; sri[si] = i+1; si++;
		sx[si] = x2; sy1[si] = y1; sy2[si] = y2; sri[si] = i+1; si++;

		a[i + 1] = 1LL * (x2 - x1) * (y2 - y1);
	}

	sort1(0, 2*n+1);

	int p[60001];
	for (i = 0; i < 2*n + 2; i++) {
		if (find_i(sy1[i]) != -1) {
			delete(sy1[i]);
			delete(sy2[i]);
		} else {
			insert(sy1[i], sri[i]);
			insert(sy2[i], -sri[i]);

			if (i != 0) {
				int ri = tv[succ_i(sy2[i])];
				if (ri > 0)
					p[sri[i]] = p[ri];
				else
					p[sri[i]] = -ri;
			}
		}
	}

	memcpy(sa, a, sizeof(a));
	for (i = 1; i <= n; i++)
		sa[p[i]] -= a[i];

	sort2(0, n);

	for (i = 0; i <= n; i++)
		printf("%lld ", sa[i]);
	putchar('\n');

	return 0;
}
