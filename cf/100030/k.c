#include <stdio.h>
#include <string.h>

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	char s[1001]; scanf("%s", s);

	int n = strlen(s);

	int m = 0;
	for (int i = 0; i <= n; i++) {
		int c = 0;
		for (int j = 0; j < i; j++)
			if (s[j] == '3')
				c++;
		for (int j = i; j < n; j++)
			if (s[j] == '1')
				c++;

		if (c > m)
			m = c;
	}

	printf("%d\n", n-m);

	return 0;
}
