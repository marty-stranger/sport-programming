#include <stdio.h>

#define M_PI 3.14159265358979323846

int main() {
	int n; scanf("%d", &n);

	int a[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	for (int i = 0; i < n; i++)
		for (int j = i+1; j < n; j++)
			if (a[j] < a[i]) {
				int t = a[j]; a[j] = a[i]; a[i] = t;
			}

	double s = 0;
	for (int i = n-1; i > 0; i -= 2)
		s += M_PI*(a[i]*a[i] - a[i-1]*a[i-1]);

	if (n % 2 == 1)
		s += M_PI*a[0]*a[0];

	printf("%.8lf\n", s);

	return 0;
}
