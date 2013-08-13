#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

int main() {
	vector<string> a;

	int n; scanf("%d\n", &n);

	for (int i = 0; i < n; i++) {
		char s[31]; gets(s);
		string ss(s);
		a.push_back(ss);
	}

	sort(a.begin(), a.end());

	int c = 0;
	for (int i = 0; i < n - 1; i++)
		if (a[i] == a[i + 1])
			c++;

	printf("%d", c);

	return 0;
}
