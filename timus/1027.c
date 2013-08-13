#include <stdio.h>

#define eol '\n'

char symbols[] = "=+-*/0123456789";

enum { text, expr, textcomm, exprcomm } state;

int issymbol(char c) {
	int i = 0;

	while (symbols[i] && symbols[i] != c)
		i++;

	return symbols[i];
}

int main() {
	char c, c1; 
	int k; 
	int f = 1;

	state = text;
	while (f && !feof(stdin)) {
		c = fgetc(stdin);

		if (state == text && c == '(') {
			c1 = fgetc(stdin);
			if (c1 == '*') {
				state = textcomm;
			} else {
				ungetc(c1, stdin);
				state = expr;
				k = 0;
			}
		} else if (state == text && c == ')') {
			f = 0;
		} else if (state == text) {
			/*ok*/
		} else if (state == expr && c == '(') {
			c1 = fgetc(stdin);
			if (c1 == '*') {
				state = exprcomm;
			} else {
				ungetc(c1, stdin);
				k++;
			}
		} else if (state == expr && c == ')') {
			if (k == 0) {
				state = text;
			} else {
				--k;
			}
		} else if (state == expr && c == eol) {
			/*c = fgetc(stdin);*/
		} else if (state == expr && issymbol(c)) {
			/*ok*/
		} else if (state == expr && !issymbol(c)) {
			f = 0;
		} else if (state == textcomm && c == '*') {
			c1 = fgetc(stdin);
			if (c1 == ')') {
				state = text;
			} else {
				ungetc(c1, stdin);
			}
		} else if (state == textcomm) {
			/*ok*/
		} else if (state == exprcomm && c == '*') {
			c1 = fgetc(stdin);
			if (c1 == ')') {
				state = expr;
			} else {
				ungetc(c1, stdin);
			}
		} else if (state == exprcomm) {
			/*ok*/
		} else {
			f = 0;
		}	
	}

	if (state != text)
		f = 0;

	if (f)
		printf("YES\n");
	else
		printf("NO\n");
	
	return 0;
}
