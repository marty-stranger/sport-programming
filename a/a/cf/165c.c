#include <stdio.h>
#include <string.h>

char s[1000001];

int main() {
	int k; scanf("%d", &k);
	scanf("%s", s);
	int n = strlen(s);

	if (k == 0) {
		long long c = 0;
		int i = 0;
		while (i < n && s[i] == '1')
			i++;
		while (i < n) {
			int j = i;
			while (j < n && s[j] == '0')
				j++;
			c += 1ll*(j-i)*(j-i+1)/2;

			while (j < n && s[j] == '1')
				j++;
			i = j;
		}

		printf("%I64d\n", c);
		return 0;
	}

	int i = 0;
	while (i < n && s[i] == '0')
		i++;

	int j = i, c = 0;
	while (j < n) {
		if (s[j] == '1')
			c++;
		if (c == k)
			break;
		j++;
	}

	long long r = 0;
	while (j < n) {
		// printf("i = %d j = %d\n", i, j);
		int ii = i-1;
		while (ii >= 0 && s[ii] == '0')
			ii--;

		int jj = j+1;
		while (j < n && s[jj] == '0')
			jj++;

		// printf("ii = %d jj = %d\n", ii, jj);

		r += 1ll*(i-ii)*(jj-j);

		j++;
		while (j < n && s[j] == '0')
			j++;

		i++;
		while (i < n && s[i] == '0')
			i++;
	}

	printf("%I64d\n", r);

	return 0;
}
