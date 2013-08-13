#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

int brute(int a, int b, int c, int d) {
	printf("brute : %d %d %d %d\n", a, b, c, d);
	int i, j, s = 0;
	for (i = a, j = c; i <= b; i++, j--) {
		int t = i, ss = 0;
		while (t != 0) {
			ss += t % 10;
			t /= 10;
		}

		// printf("ss = %d\n", ss);

		t = j; int p = 1;
		while (t != 0) {
			p *= t % 10;
			t /= 10;
		}

		if (j == 0)
			p = 0;

		// printf("p = %d\n", p);

		s += ss * p;
	}

	return s;
}

int cnt(int a) {
	if (a == 0)
		return 1;

	int c = 0;
	while (a != 0) {
		a /= 10;
		c++;
	}

	return c;
}

typedef pair<int, int> pii;

map<pii, int> m2;

int count2(int c, int d) {
	printf("c2: %d %d\n", c, d);
	if (c < d)
		return 0;
	pii p = make_pair(c, d);
	if (m2.find(p) != m2.end())
		return m2[p];

	int t = c, z = 1;
	while (t / 10 != 0) {
		z *= 10;
		t /= 10;
	}
	int cc = (c/z)*z;

	int r;
	if (cnt(c) == 1 && cnt(d) == 1) {
		int s = 0, i;
		for (i = c; i >= d; i--)
			s += i;
		r = s;
	} else if (cnt(c) == cnt(d) && c/z == d/z) {
		r = (c/z) * count2(c % z, d % z);
	} else {
		int y = c - cc;
		r = count2(c, c-y) + count2(c-y-1, d);
	}

	printf("-> %d\n", r);
	return m2[p] = r;
}

map<pair<pii, pii>, int> m;

int count(int a, int b, int c, int d) {
	if (a > b || c < d)
		return 0;
	pair<pii, pii> p = make_pair(make_pair(a, b), make_pair(c, d));
	if (m.find(p) != m.end())
		return m[p];

	printf("count: %d %d %d %d\n", a, b, c, d);

	if (cnt(a) == 1 && cnt(b) == 1 && cnt(c) == 1 && cnt(d) == 1) {
		int s = 0, aa, cc;
		for (aa = a, cc = c; aa <= b; aa++, cc--)
			s += aa*cc;
		return m[p] = s;
	}

	int t = c, z = 1;
	while (t / 10 != 0) {
		z *= 10;
		t /= 10;
	}

	int zz = z;
	int cc = (c/z)*z;

	if (c / 10 == 0) {
		zz = 1;
		cc = 0;
	}

	if (cnt(c) > 1 && cnt(c) == cnt(d) && c/z == d/z) {
		int pp = 1, cc = c, dd = d;
		while (z != 1 && cc/z == dd/z) {
			pp *= cc/z;
			cc = cc % z; dd = dd % z;
			z /= 10;
		}

		if (cnt(dd) < cnt(cc)) {
			int ddd = (cc/z) * z;
			b -= (ddd - dd);
			dd = ddd;
		}

		m[p] = pp * count(a, b, cc, dd);
		if (m[p] != brute(a, b, c, d)) {
			puts("fuckup1");
			printf("%d %d\n", m[p], brute(a, b, c, d));
			exit(1);
		}
		return m[p];
	}

	t = a, z = 1;
	while (t / 10 != 0) {
		z *= 10;
		t /= 10;
	}

	int aa = (a/z+1)*z-1;

	if (cnt(a) == cnt(b) && a/z == b/z) {
		m[p] = (a/z) * count2(c, d) + count(a % z, b % z, c, d);
		if (m[p] != brute(a, b, c, d)) {
			puts("fuckup2");
			printf("%d %d\n", m[p], brute(a, b, c, d));
			exit(1);
		}
		return m[p];
	}
	
	int y = min(aa - a, c - cc);
	m[p] = count(a, a+y, c, c-y) + count(a+y+1, b, c-y-1, d);
	if (m[p] != brute(a, b, c, d)) {
		puts("fuckup3");
		printf("%d %d\n", m[p], brute(a, b, c, d));
		printf("fork: %d %d %d %d\n", a, a+y, c, c-y);
		printf("fork: %d %d %d %d\n", a+y+1, b, c-y-1, d);
		exit(1);
	}
	return m[p];
}

int main() {
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	int a, b, c, d; scanf("%d%d%d%d", &a, &b, &c, &d);

	printf("%d", count(a, b, c, d));

	return 0;
}
