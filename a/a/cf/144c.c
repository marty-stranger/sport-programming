#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	char s[100001], p[100001];

	gets(s);
	gets(p);

	int sn = strlen(s), pn = strlen(p);

	if (pn > sn) {
		puts("0");
		return 0;
	}

	int i, c[200];
	memset(c, 0, sizeof(c));
	for (i = 0; i < pn; i++)
		c[p[i]]++;

	int d = 0;
	for (i = 0; i < pn; i++)
		c[s[i]]--;
	
	char ch;
	for (ch = 'a'; ch <= 'z'; ch++)
		if (c[ch] < 0)
			d++;

	int t = 0;
	if (d == 0)
		t++;

	for (i = pn; i < sn; i++) {
		ch = s[i - pn];
		c[ch]++;
		if (ch != '?' && c[ch] == 0)
			d--;

		ch = s[i];
		c[ch]--;
		if (ch != '?' && c[ch] == -1)
			d++;

		if (d == 0)
			t++;
	}

	printf("%d", t);
	
	return 0;
}
