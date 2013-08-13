#include <stdio.h>

int main() {
	char s[200001];
	gets(s);

	char *t = s;
	int stn = 0;
       	char st[200001];
	while (*t != 0) {
		if (stn > 0 && *t == st[stn-1])
			stn--;
		else
			st[stn++] = *t;
		t++;
	}

	st[stn] = '\0';
	
	puts(st);

	return 0;
}
