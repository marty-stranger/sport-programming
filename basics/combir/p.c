#include <stdio.h>

int n, p[10];

void f(int m) {
	int i, j, t;
	
	if (m == 1) {
		for (i = 0; i < n; i++)
			printf("%d ", p[i] + 1);
		printf("\n");
		return;
	}

	for (i = 0; i < m; i++) {
		f(m - 1);
                if (i + 1 < m) {
                        j = m % 2 == 0 && m > 2 ? i + 2 < m ? i + 1 : m - 2 : m - 1;
                        t = p[m - 1]; p[m - 1] = p[j - 1]; p[j - 1] = t;
                }
	}
}

int main() {
	int i;
	n = 5;

	for (i = 0; i < n; i++)
		p[i] = i;
	f(n);

	return 0;
}
