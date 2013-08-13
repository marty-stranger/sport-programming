#include <vector>
#include <cstdio>
using namespace std;

#define BITS_COUNT 32
#define LOW_BITS_COUNT 5

int a[3000], b[3000];
vector<vector<vector<bool> > > c, p;
//char c[3001][3][3001 / BITS_COUNT + 1], p[3001][3][3001 / BITS_COUNT + 1]

void out(int i, int j, int k) {
	if (i != 0 || j != 0) {
		if (!p[k][i][j])
			out(i - 1, j, k - a[i - 1]);
		else
			out(i, j - 1, k - b[j - 1]);

		putchar((int)p[k][i][j] + '1');
	}
}

int main() {
	int n, i, j, k, kk;
	char s[3001];

	scanf("%d", &n);

	c = vector<vector<vector<bool> > >(3, vector<vector<bool> >(n + 1, vector<bool>(n + 1)));
	p = vector<vector<vector<bool> > >(3, vector<vector<bool> >(n + 1, vector<bool>(n + 1)));

	//c = vector<vector<vector<int> > >(3, vector<vector<int> >(n + 1, vector<int>(n + 1)));
	//p = vector<vector<vector<int> > >(3, vector<vector<int> >(n + 1, vector<int>(n + 1)));

	scanf("%s", s);
	for (i = 0; i < n; i++)
		a[i] = s[i] == '1' ? 1 : -1;
	scanf("%s", s);
	for (i = 0; i < n; i++)
		b[i] = s[i] == '1' ? 1 : -1;

	c[0][0][0] = c[2][0][0] = 0;
	c[1][0][0] = 1;

	for (j = 1; j <= n; j++)
		for (k = 0; k < 3; k++) {
			kk = k - b[j - 1];
			if (0 <= kk && kk < 3) {
				c[k][0][j] = c[kk][0][j - 1];
				p[k][0][j] = 1;
			} else
				c[k][i][0] = 0;
		}

	for (i = 1; i <= n; i++)
		for (k = 0; k < 3; k++) {
			kk = k - a[i - 1];
			if (0 <= kk && kk < 3) {
				c[k][i][0] = c[kk][i - 1][0];
				p[k][i][0] = 0;
			} else
				c[k][i][0] = 0;
		}

	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			for (k = 0; k < 3; k++) {
				c[k][i][j] = 0;

				kk = k - a[i - 1];
				if (0 <= kk && kk < 3 && c[kk][i - 1][j] == 1) {
					c[k][i][j] = 1;
					p[k][i][j] = 0;
				}
				kk = k - b[j - 1];
				if (0 <= kk && kk < 3 && c[kk][i][j - 1] == 1) {
					c[k][i][j] = 1;
					p[k][i][j] = 1;
				}
			}

	if (c[1][n][n])
		out(n, n, 1);
	else
		puts("Impossible");
	
	return 0;
}
