#include <stdbool.h>
#include <stdio.h>

int count(int a) {
	int c = 0;
	for (int d = 2; d*d <= a; d++)
		if (a%d == 0) {
			c++;
			while (a%d == 0)
				a /= d;
		}

	if (a != 1)
		c++;

	return 1 << c;
}

int main() {
	int tn; scanf("%d", &tn);

	for (int ti = 0; ti < tn; ti++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);

		int r = 0, inf = false;
		if (a != 0) {
			for (int d = 1; d <= a; d++)
				if (a%d == 0)
					if (d == b) {
						if (a + c*d == 0)
							inf = true;
					} else if ((a/d+c)%(d-b) == 0 && d > b) {
						int t = (a/d+c)/(d-b);
						r += count(t);
					}
		} else if (c != 0) {
			for (int d = 1; d-b <= c; d++)
				if (d != b && c%(d-b) == 0 && d > b) {
					int t = c/(d-b);
					r += count(t);
				}
		} else if (b != 0)
			inf = true;

		if (inf)
			puts("-1");
		else
			printf("%d\n", r);
	}

	return 0;
}
