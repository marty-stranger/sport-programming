#include <stdio.h>
#include <string.h>

int main() {
	int n, a, i, j, k, l, s[100000];
	
	scanf("%d", &n);

	k = 0;
	l = 0;
	for (i = 0; i < n; i++) {
		scanf("%d", &a);

		if (a > l) {
			j = l+1;
			while (j < a)
				s[k++] = j++;
			l = a;
		} else
			if (a != s[k-1])
				break;
			else 
				k--;
	}

	if (i == n)
		puts("Not a proof");
	else
		puts("Cheater");

	return 0;
}

