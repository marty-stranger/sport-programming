#include <stdio.h>
#include <string.h>

int main() {
	char p[100000], s[100000];
	gets(p); gets(s);

	int pl = strlen(p), sl = strlen(s);

	int i, k = 0, l[1000000];
	l[0] = 0;
	for (i = 1; i < pl; i++) {
		while (k > 0 && p[k] != p[i])
			k = l[k-1];
		if (p[k] == p[i])
			k++;
		l[i] = k;
	}

	k = 0;
	for (i = 0; i < sl; i++) {
		while (k > 0 && p[k] != s[i])
			k = l[k-1];
		if (p[k] == s[i])
			k++;

		if (k == pl) {
			printf("i = %d\n", i-pl+1);
			k = l[k-1];
		}
	}

	return 0;
}
