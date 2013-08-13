#include <stdio.h>
#include <string.h>

int main() {
	char s[100], t[100];
	scanf("%s%s", s, t);

	int n = strlen(s);
	int c[10]; memset(c, 0, sizeof(c));
	for (int i = 0; i < n; i++)
		c[s[i]-'0']++;

	int j = 0;
	for (int i = 1; i < 10; i++)
		if (c[i] > 0) {
			s[j] = i + '0';
			c[i]--;
			j++;
			break;
		}

	for (int i = 0; i < 10; i++)
		while (c[i] > 0) {
			s[j] = i + '0';
			c[i]--;
			j++;
		}

	if (!strcmp(s, t))
		puts("OK");
	else
		puts("WRONG_ANSWER");

	return 0;
}
