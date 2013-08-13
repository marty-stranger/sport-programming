#include <stdio.h>
#include <string.h>

int main() {
	char my_name[100];
	gets(my_name);

	int n; scanf("%d\n", &n);

	int i, names_n = 0, rating[200];
	char *names[200];
	memset(rating, 0, sizeof(rating));
	for (i = 0; i < n; i++) {
		char x[100], act[100];
		scanf("%s %s", x, act);

		char y[100];
		if (!strcmp(act, "posted") || !strcmp(act, "commented"))
			scanf("%s %s", y, y);
		else 
			scanf("%s", y);

		y[strlen(y) - 2] = 0;

		char t[100];
		gets(t);

		int j;
		for (j = 0; j < names_n; j++)
			if (!strcmp(names[j], x))
				break;

		if (j == names_n) {
			names[j] = strdup(x);
			names_n++;
		}

		for (j = 0; j < names_n; j++)
			if (!strcmp(names[j], y))
				break;

		if (j == names_n) {
			names[j] = strdup(y);
			names_n++;
		}

		char friend[100];
		if (!strcmp(x, my_name))
			strcpy(friend, y);
		else if (!strcmp(y, my_name))
			strcpy(friend, x);
		else
			continue;

		for (j = 0; j < names_n; j++)
			if (!strcmp(names[j], friend))
				break;

		if (!strcmp(act, "likes"))
			rating[j] += 5;
		else if (!strcmp(act, "commented"))
			rating[j] += 10;
		else
			rating[j] += 15;
	}

	int j;
	for (i = 0; i < names_n; i++)
		for (j = i+1; j < names_n; j++)
			if (rating[j] > rating[i] || rating[j] == rating[i] && strcmp(names[j], names[i]) < 0) {
				char *ts = names[i]; names[i] = names[j]; names[j] = ts;
				int t = rating[i]; rating[i] = rating[j]; rating[j] = t;
			}

	for (i = 0; i < names_n; i++) {
		if (!strcmp(names[i], my_name))
			continue;
		puts(names[i]);
		// printf("%d\n", rating[i]);
	}

	return 0;
}
