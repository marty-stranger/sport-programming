#include <stdio.h>

int f, root, k[1000], c[1000], l[1000], r[1000];

int rotate_left(int i) {
	int j = r[i]; r[i] = l[j]; l[j] = i;
	c[j] = c[i]; c[i] = 1;
	return j;
}

int rotate_right(int i) {
	int j = l[i]; l[i] = r[j]; r[j] = i;
	c[j] = c[i]; c[i] = 1;
	return j;
}

void flip_colors(int i) {
	c[i] = !c[i]; c[l[i]] = !c[l[i]]; c[r[i]] = !c[r[i]];
}

int is_red(int i) {
	return i != -1 && c[i] == 1;
}

void insert(int x) {
	int insert_rec(int i) {
		if (i == -1) {
			i = f; f++;
			k[i] = x; l[i] = r[i] = -1; c[i] = 1; 
			return i;
		}

		if (x < k[i])
			l[i] = insert_rec(l[i]);
		else
			r[i] = insert_rec(r[i]);

		if (is_red(r[i]) && !is_red(l[i]))
			i = rotate_left(i);
		if (is_red(l[i]) && is_red(l[l[i]]))
			i = rotate_right(i);
		if (is_red(l[i]) && is_red(r[i]))
			flip_colors(i);

		return i;
	}

	root = insert_rec(root);
	c[root] = 0;
}

int find(int x) {
	int i = root;

	while (i != -1 && k[i] != x)
		if (x < k[i])
			i = l[i];
		else
			i = r[i];

	return i != -1;
}

int move_red_left(int i) {
	flip_colors(i);

	if (is_red(l[r[i]])) {
		r[i] = rotate_right(r[i]);
		i = rotate_left(i);
		flip_colors(i);
	}

	return i;
}

int move_red_right(int i) {
	flip_colors(i);

	if (is_red(l[l[i]])) {
		i = rotate_left(i);
		flip_colors(i);
	}

	return i;
}

int fix_up(int i) {
	if (is_red(r[i]))
		i = rotate_left(i);
	if (is_red(l[i]) && is_red(l[l[i]]))
		i = rotate_right(i);
	if (is_red(l[i]) && is_red(r[i]))
		flip_colors(i);

	return i;
}

int min_rec(int i) {
	while (l[i] != -1)
		i = l[i];
	return k[i];
}

int delete_min_rec(int i) {
	if (l[i] == -1)
		return -1;

	if (!is_red(l[i]) && !is_red(l[l[i]]))
		i = move_red_left(i);

	l[i] = delete_min_rec(l[i]);

	return fix_up(i);
}

void delete(int x) {
	int delete_rec(int i) {
		if (x < k[i]) {
			if (!is_red(l[i]) && !is_red(l[l[i]]))
				i = move_red_left(i);
			l[i] = delete_rec(l[i]);
		} else {
			if (is_red(l[i]))
				i = rotate_right(i);
			
			if (x == k[i] && r[i] == -1) {
				return -1;
			}

			if (!is_red(r[i]) && !is_red(l[r[i]]))
				i = move_red_right(i);

			if (x == k[i]) {
				k[i] = min_rec(r[i]);
				r[i] = delete_min_rec(r[i]);
			} else
				r[i] = delete_rec(r[i]);
		}

		return fix_up(i);
	}

	root = delete_rec(root);
	c[root] = 0;
}

void print() {
	void print_rec(int i) {
		if (i != -1) {
			print_rec(l[i]);
			printf("%d:%c ", k[i], c[i] ? 'r' : 'b');
			print_rec(r[i]);
		}
	}

	print_rec(root);
	putchar('\n');
}

int main() {
	char c;
	int x;

	f = 0; root = -1;

	while (1) {
		scanf("%c", &c);
		if (c != 'p')
			scanf("%d", &x);

		switch (c) {
			case 'i':
				insert(x);
				break;
			case 'd':
				delete(x);
				break;
			case 'f':
				printf("find: %d\n", find(x));
				break;
			case 'p':
				print();
		}
	}
}
