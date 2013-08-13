int main() {
	int n, i, j, l, st;
	char s[101], c;

	freopen("i.in", "r", stdin);

	scanf("%d\n", &n);
	for (i = 0; i < n; i++) {
		gets(s);
		
		st = 0;
		l = strlen(s);
		for (j = 0; j < l && st != -1; j++) {
			c = s[j];
			if (st == 0)
				if (isalnum(c) || c == '_' || c == '-')
					st = 1;
				else
					st = -1;
			else if (st == 1)
				if (isalnum(c) || c == '_' || c == '-')
					;
				else if (c == '.')
					st = 0;
				else if (c == '@')
					st = 2;
				else
					st = -1;
			else if (st == 2)
				if (isalnum(c) || c == '_' || c == '-')
					st = 3;
				else
					st = -1;
			else if (st == 3)
				if (isalnum(c) || c == '_' || c == '-')
					;
				else if (c == '.')
					st = 4;
				else
					st = -1;
			else if (st == 4)
				if (isalnum(c) || c == '_' || c == '-')
					st = 5;
				else
					st = -1;
			else if (st == 5)
				if (isalnum(c) || c == '_' || c == '-')
					;
				else if (c == '.')
					st = 4;
				else
					st = -1;			
		}
		
		if (st == 5 && isalpha(s[l-1]) && isalpha(s[l-2]) && (s[l-3] == '.' || isalpha(s[l-3]) && s[l-4] == '.'))
			printf("YES");
		else
			printf("NO");
		putchar('\n');}

	return 0