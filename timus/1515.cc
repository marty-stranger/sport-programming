#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> a;
	for (int i = 0; i < n; i++) {
		int aa; cin >> aa;
		a.push_back(aa);
	}

	int k = 0, m = 0;
	while (k < n && a[k] <= m + 1) {
		m += a[k];
		k++;
	}

	cout << m + 1;

	return 0;
}
