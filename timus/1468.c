#include <stdio.h>

int p;

void out(int a) {
	if (0 <= a && a < 10)
		putchar(a + '0');
	else
		putchar(a - 10 + 'A');
}

void outp(int a) {
	if (a == 0)
		return;
		
	outp(a / p);
	out(a % p);
}

int main() {
	int n, nn, m, i, j, l, k, rr, f;
	int r[20001], a[20001];

	scanf("%d%d", &n, &m);
	while (n != 0 && m != 0) {
		scanf("%d", &p);

		i = n/m;
		if (i == 0)
			putchar('0');
		else
			outp(i);

		nn = n % m;
		if (nn != 0) {
			putchar('.');

			i = 0;
			for (i = 0; i < m; i++) {
				r[i] = nn;
				a[i] = nn * p / m;
				nn = nn * p % m;
			}

			rr = r[m-1];
			for (j = m;; j++) {
				r[j] = nn;
				a[j] = nn * p / m;
				nn = nn * p % m;
				if (r[j] == rr)
					break;
			}

			k = j-i+1;
			
			for (j = 0;; j++)
				if (r[j+k] == r[j]) {
					i = j+k;
					break;
				}

			for (l = 0; l < j; l++)
				out(a[l]);
			if (!(j+1 == i && a[i] == 0)) {
				putchar('(');
				for (l = j; l < i; l++)
					out(a[l]);
				putchar(')');
			}
		}
	
		putchar('\n');

		scanf("%d%d", &n, &m);
	}

	return 0;
}

