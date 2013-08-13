#include <map>
#include <algorithm>
#include <fstream>
#include <iostream>
using namespace std;

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

map<pii, long long> m2;

long long count2(int c, int d) {
	// printf("c2: %d %d\n", c, d);
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

	long long r;
	int cn = cnt(c), dn = cnt(d);
	if (cn == 1 && dn == 1) {
		long long s = 0;
	       	int i;
		for (i = c; i >= d; i--)
			s += i;
		r = s;
	} else if (cn == dn && c/z == d/z) {
		/* int pp = 1, cc = c, dd = d;
		while (z != 1 && cc/z == dd/z) {
			pp *= cc/z;
			cc = cc % z; dd = dd % z;
			z /= 10;
		}

		if (cnt(dd) < cnt(cc))
			dd = (dd/z+1) * z;

		r = pp * count2(cc, dd); */

		if (c/z == 0)
			r = 0;
		else {
			int pp = c/z, cc = c%z, dd = d%z;
			z /= 10;

			if (cc/z == dd/z && cc/z == 0)
				r = 0;
			else {
				if (cnt(dd) < cnt(cc))
					dd = (dd/z+1)*z;
				r = pp*count2(cc, dd);
			}
		}
	} else {
		int y = c - cc;
		r = count2(c, c-y) + count2(c-y-1, d);
	}

	// printf("-> %d\n", r);
	return m2[p] = r;
}

map<pair<pii, int>, long long> m;

long long count(int a, int b, int c, int d) {
	if (a > b || c < d)
		return 0;
	pair<pii, int> p = make_pair(make_pair(a, b), c);
	if (m.find(p) != m.end())
		return m[p];

	// printf("count: %d %d %d %d\n", a, b, c, d);

	if (a / 10 == 0 && b / 10 == 0 && c / 10 == 0 && d / 10 == 0) {
	// if (cnt(a) == 1 && cnt(b) == 1 && cnt(c) == 1 && cnt(d) == 1) {
		long long s = 0;
		int aa, cc;
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

	int cn = cnt(c), dn = cnt(d);
	if (cn > 1 && cn == dn && c/z == d/z) {
		if (c/z == 0)
			return m[p] = 0;
		else {
			int pp = c/z, cc = c%z, dd = d%z;
			z /= 10;

			if (cc/z == dd/z && cc/z == 0)
				return m[p] = 0;
			else {
				if (cnt(dd) < cnt(cc)) {
					int ddd = (dd/z+1)*z;
					b -= ddd - dd;
					dd = ddd;
				}
				return m[p] = pp*count(a, b, cc, dd);
			}
		}

		/* int pp = 1, cc = c, dd = d;
		while (z != 1 && cc/z == dd/z) {
			pp *= cc/z;
			if (pp == 0)
				return m[p] = 0;
			cc = cc % z; dd = dd % z;
			z /= 10;
		}

		if (cnt(dd) < cnt(cc)) {
			int ddd = (dd/z+1) * z;
			b -= (ddd - dd);
			dd = ddd;
		}

		return m[p] = pp * count(a, b, cc, dd); */
	}

	t = a, z = 1;
	while (t / 10 != 0) {
		z *= 10;
		t /= 10;
	}

	int aa = (a/z+1)*z-1;
	if (a / 10 == 0) {
		z = 1;
		aa = 9;
	}

	if (cnt(a) == cnt(b) && a/z == b/z)
		return m[p] = (a/z) * count2(c, d) + count(a % z, b % z, c, d);
	
	int y = min(aa - a, c - cc);
	return m[p] = count(a, a+y, c, c-y) + count(a+y+1, b, c-y-1, d);
}

int main() {
	ifstream cin("input.txt");
	ofstream cout("output.txt");

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		cout << count(a, b, b, a) << endl;
	}

	// printf("%d\n", cc);

	return 0;
}

