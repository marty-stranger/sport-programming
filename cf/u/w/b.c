#include <stdio.h>
#include <string.h>

int main() {
	char a[100000+1];
	scanf("%s", a);

	char s[100000+1];
	scanf("%s", s);

	int l = strlen(s), cs[10] = {0};
	for (int i = 0; i < l; i++)
		cs[s[i]-'0']++;

	int j = 9;
	while (j >= 0 && cs[j] == 0)
		j--;

	int n = strlen(a);
	for (int i = 0; i < n; i++)
		if (j != -1 && j+'0' > a[i]) {
			a[i] = j+'0';
			cs[j]--;
			while (j >= 0 && cs[j] == 0)
				j--;
		}

	printf("%s", a);

	return 0;
}
