#include <algorithm>
#include <cstdio>
#include <map>
#include <vector>
using namespace std;

struct event {
	int x, y1, y2, i;

	event(int _x, int _y1, int _y2, int _i) : x(_x), y1(_y1), y2(_y2), i(_i) {}
	event() {}

	inline bool operator<(const event &e) const {
		return this->x < e.x || this->x == e.x && this->y1 < e.y1;
	}
};

int main() {
	int n, x, y; scanf("%d%d%d", &n, &x, &y);

	event s[2*60000+2];
	long long a[60001];

	s[0] = event(0, 0, y, 0);
	s[1] = event(x, 0, y, 0);
	a[0] = 1LL * x * y;

	for (int i = 0; i < n; i++) {
		int x1, y1, x2, y2; scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		if (x1 > x2)
			swap(x1, x2);
		if (y1 > y2)
			swap(y1, y2);

		s[2 + 2*i] = event(x1, y1, y2, i + 1);
		s[2 + 2*i+1] = event(x2, y1, y2, i + 1);

		a[i + 1] = 1LL * (x2 - x1) * (y2 - y1);
	}


	sort(s, s + 2*n + 2);

	map<int, int> m;

	int p[60001];
	for (int i = 0; i < 2*n + 2; i++) {
		event &e = s[i];

		map<int, int>::iterator it = m.find(e.y1);
		if (it != m.end()) {
			// m.erase(it, ++++it);
			m.erase(it++);
			m.erase(it);
		} else {
			it = m.insert(make_pair(e.y1, e.i)).first;
			it = m.insert(it, make_pair(e.y2, -e.i));

			if (i != 0) {
				it++;
				int ri = it->second;

				if (ri > 0)
					p[e.i] = p[ri];
				else
					p[e.i] = -ri;
			}
		}
	}

	long long sa[60001];
	for (int i = 0; i <= n; i++)
		sa[i] = a[i];

	for (int i = 1; i <= n; i++)
		sa[p[i]] -= a[i];

	sort(sa, sa + n + 1);

	for (int i = 0; i <= n; i++)
		printf("%lld ", sa[i]);
	putchar('\n');

	return 0;
}
