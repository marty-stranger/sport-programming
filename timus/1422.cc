#include <cmath>
#include <cstdio>
#include <algorithm>
#include <unordered_map>
using namespace std;

double dx[2000], dy[2000], dz[2000];

struct thash : unary_function<int, size_t> {
	size_t operator()(int i) const {
		return (dx[i] * 100000 + dy[i]) * 100000 + dz[i];
	}
};

struct teq : binary_function<int, int, bool> {
	bool operator()(int i, int j) const {
		return dx[i] == dx[j] && dy[i] == dy[j] && dz[i] == dz[j];
	}
};

int main() {
	int n; scanf("%d", &n);

	int x[2000], y[2000], z[2000];
	for (int i = 0; i < n; i++)
		scanf("%d%d%d", &x[i], &y[i], &z[i]);

	if (n == 1) {
		printf("1");
		return 0;
	}

	unordered_map<int, int, thash, teq> a;
	int m = 1;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			dx[j] = x[j] - x[i];
			dy[j] = y[j] - y[i];
			dz[j] = z[j] - z[i];

			if (dx[j] < 0 || (dx[j] == 0 && dy[j] < 0) || (dx[j] == 0 && dy[j] == 0 && dz[j] < 0)) {
				dx[j] = -dx[j]; dy[j] = -dy[j]; dz[j] = -dz[j];
			}

			double d = max(fabs(dx[j]), max(fabs(dy[j]), fabs(dz[j])));
			dx[j] /= d; dy[j] /= d; dz[j] /= d;

			int c = a[j];
			a[j] = c + 1;

			if (c + 2 > m)
				m = c + 2;
		}
		a.clear();
	}

	printf("%d\n", m);
	
	return 0;
}
