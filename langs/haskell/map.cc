#include <map>
#include <cstdio>

using namespace std;

int main() {
	int n = 5 * 100000;
	int a[5 * 100000];
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	map<int, int> m;

	int b[5 * 100000];

	for (int i = 0; i < n; i++) {
		int x = a[i];
		if (m.find(x) == m.end())
			b[i] = -1;
		else
			b[i] = m[x];

		m[x] = i;
	}

	int s = 0;
	for (int i = 0; i < n; i++)
		s += (b[i] + 1);

	printf("%d\n", s);

	return 0;
}
