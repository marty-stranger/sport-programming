#include <stdio.h>

const int m = 1000000000 + 9;
typedef long long int64;

int bpow(int64 a, int64 p) {
	int64 b = 1;
	while (p) {
		if (p & 1)
			b = (b * a) % m;
		a = (a * a) % m;
		p >>= 1;
	}

	return b;
}

int inv(int64 a) {
	return bpow(a, m-2);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int nn;
	scanf("%d", &nn);
	n = nn;

	int i;
	for (i = 2; i <= n; i++) {
		int j;
		for (j = 0; j < pn; j++)
			if (i % p[j] == 0)
				break;

		if (j == pn)
			p[pn++] = i;
	}

	n = n*(n-1)/2;

	int64 a = n;
	for (i = 0; i < pn; i++)
		if (a % p[i] == 0) {
			np[npn] = p[i]; npc[npn] = 0;
			while (a % p[i] == 0) {
				npc[npn]++;
				a /= p[i];
			}
			npn++;
		}

	rec(0, 1);

	printf("%d\n", (1LL*s*inv(nn)) % m);

	return 0;
}
