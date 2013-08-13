/* ok */
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;

int p[2000];
double dx[2000], dy[2000], dz[2000];
const double eps = 1e-8;

inline double max(double a, double b) {
	return a > b ? a : b;
}

struct cmps {
	inline bool operator()(int i, int j) {
		if (dx[i] <= dx[j] - eps)
			return -1;
		else if (dx[i] >= dx[j] + eps)
			return 0;
		if (dy[i] <= dy[j] - eps)
			return -1;
		else if (dy[i] >= dy[j] + eps)
			return 0;
		if (dz[i] <= dz[j] - eps)
			return -1;
		else
			return 0;
	}
};

bool eq(int i, int j) {
	return fabs(dx[i] - dx[j]) < eps && fabs(dy[i] - dy[j]) < eps &&
			fabs(dz[i] - dz[j]) < eps;
}

int main() {
	int n, i, j, m, c;
	double x[2000], y[2000], z[2000];
	double d;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%lf%lf%lf", &x[i], &y[i], &z[i]);

	if (n == 1) {
		printf("1");
		return 0;
	}

	m = 2;
	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++) {
			dx[j] = x[j] - x[i];
			dy[j] = y[j] - y[i];
			dz[j] = z[j] - z[i];

			d = max(fabs(dx[j]), max(fabs(dy[j]), fabs(dz[j])));
			dx[j] /= d;
			dy[j] /= d;
			dz[j] /= d;

			if (dx[j] < 0) {
				dx[j] = -dx[j];
				dy[j] = -dy[j];
				dz[j] = -dz[j];
			}

			if (dx[j] == 0 && dy[j] < 0) {
				dy[j] = -dy[j];
				dz[j] = -dz[j];
			}

			if (dx[j] == 0 && dy[j] == 0 && dz[j] < 0) {
				dz[j] = -dz[j];
			}

			p[j] = j;
		}

		sort(p + i + 1, p + n, cmps());

		c = 1;
		for (j = i + 2; j < n; j++)
			if (eq(p[j], p[j - 1]))
				c++;
			else {
				if (c + 1 > m)
					m = c + 1;
				c = 1;
			}
		if (c + 1 > m)
			m = c + 1;
	}

	printf("%d", m);
	
	return 0;
}
