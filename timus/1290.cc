#include <algorithm>
#include <cstdio>
using namespace std;

int a[25000];

int main() {
	int n; scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	sort(a, a + n);

	for (int i = n - 1; i >= 0; i--)
		printf("%d\n", a[i]);
	
	return 0;
}

