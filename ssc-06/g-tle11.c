// non-balanced binary trees
#include <stdio.h>
#include <string.h>

void swap(int *a, int *b) {
	int t = *a; *a = *b; *b = t;
}

int sx[2*60000+2], sy1[2*60000+2], sy2[2*60000+2], sri[2*60000+2];

void sort1(int l, int r) {
	int i, j, px, py, t;

	if (l < r) {
		i = l; j = r; px = sx[(l + r) / 2]; py = sy1[(l + r) / 2];
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

int troot, tf, tk[2*60000+2], tv[2*60000+2], tl[2*60000+2], tr[2*60000+2];

int find(int k) {
	int i = troot;

	while (i != -1 && tk[i] != k)
		if (k < tk[i])
			i = tl[i];
		else
			i = tr[i];

	return i;
}

void insert(int k, int v) {
	int *i = &troot; 

	while (*i != -1)
		if (k < tk[*i])
			i = &tl[*i];
		else
			i = &tr[*i];

	tk[tf] = k; tv[tf] = v; tl[tf] = -1; tr[tf] = -1;
	*i = tf; tf++;
}

void delete(int k) {
	int *i = &troot, *j;

	while (tk[*i] != k)
		if (k < tk[*i])
			i = &tl[*i];
		else
			i = &tr[*i];

	if (tl[*i] == -1 && tr[*i] == -1)
		*i = -1;
	else if (tl[*i] == -1)
		*i = tr[*i];
	else if (tr[*i] == -1)
		*i = tl[*i];
	else {
		j = &tr[*i];
		while (tl[*j] != -1)
			j = &tl[*j];
		tk[*i] = tk[*j];
		tv[*i] = tv[*j];
		*j = tr[*j];
	}
}

int succ(int k) {
	int i = troot, j;

	while (tk[i] != k)
		if (k < tk[i]) {
			j = i;
			i = tl[i];
		} else
			i = tr[i];

	if (tr[i] == -1)
		return j;

	i = tr[i];
	while (tl[i] != -1)
		i = tl[i];
	return i;
}

long long s[60001], ss[60001];

void sort2(int l, int r) {
	int i, j, p;
	long long t;

	if (l < r) {
		i = l; j = r; p = ss[(l + r) / 2];
		while (i <= j)
			if (ss[i] < p)
				i++;
			else if (ss[j] > p)
				j--;
			else {
				t = ss[i]; ss[i] = ss[j]; ss[j] = t;
				i++; j--;
			}

		sort2(i, r); sort2(l, j);
	}

}

int main() {
	int n, x1, y1, x2, y2, si, i, ri, p[60001];

	scanf("%d%d%d", &n, &x2, &y2);

	si = 0;
	sx[si] = 0; sy1[si] = 0; sy2[si] = y2; sri[si] = 0; si++;
	sx[si] = x2; sy1[si] = 0; sy2[si] = y2; sri[si] = 0; si++;

	s[0] = 1LL * x2 * y2;

	for (i = 0; i < n; i++) {
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		if (x1 > x2)
			swap(&x1, &x2);
		if (y1 > y2)
			swap(&y1, &y2);

		sx[si] = x1; sy1[si] = y1; sy2[si] = y2; sri[si] = i+1; si++;
		sx[si] = x2; sy1[si] = y1; sy2[si] = y2; sri[si] = i+1; si++;

		s[i + 1] = 1LL * (x2 - x1) * (y2 - y1);
	}

	sort1(0, 2*n+1);

	troot = -1; tf = 0;

	for (i = 0; i < 2*n + 2; i++) {
		if (find(sy1[i]) != -1) {
			delete(sy1[i]);
			delete(sy2[i]);
		} else {
			insert(sy1[i], sri[i]);
			insert(sy2[i], -sri[i]);

			if (i != 0) {
				ri = tv[succ(sy2[i])];
				if (ri > 0)
					p[sri[i]] = p[ri];
				else
					p[sri[i]] = -ri;
			}
		}
	}

	memcpy(ss, s, sizeof(s));
	for (i = 1; i <= n; i++)
		ss[p[i]] -= s[i];

	sort2(0, n);

	for (i = 0; i <= n; i++)
		printf("%d ", ss[i]);
	putchar('\n');

	return 0;
}
