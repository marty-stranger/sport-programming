#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int a[100000];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int k; scanf("%d", &k);
	char s[100000+1]; scanf("%s", s);

	int n = strlen(s);

	int cs[200] = {0};

	int l = 0, r = 0, c = 0;
	while (r < n) {
		// printf("r = %d c = %d\n", r, c);
		if (cs[s[r]] == 0)
			c++;

		if (c > k) {
			c--;
			break;
		}

		cs[s[r]]++;
		r++;
	}
	r--;

	int ml = l, mr = r;
	while (r+1 < n) {
		// printf("l = %d r = %d c = %d\n", l, r, c);
		r++;
		if (cs[s[r]] == 0)
			c++;
		cs[s[r]]++;

		while (c > k) {
			cs[s[l]]--;
			if (cs[s[l]] == 0)
				c--;
			l++;
		}

		// printf("l' = %d r' = %d c' = %d\n", l, r, c);

		if (r-l > mr-ml) {
			ml = l; mr = r;
		}
	}

	printf("%d %d\n", ml+1, mr+1);

	return 0;
}
