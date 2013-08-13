// ok. time: O(n^2*?). mem: O(n)
#include <stdio.h>

int a[2000], p[2000];

void sort(int l, int r) {
	int i, j, x, t;

	if (l < r) {
		i = l; j = r; x = p[l + rand()%(r - l)];
		while (i <= j)
			if (a[p[i]] < a[x])
				i++;
			else if (a[x] < a[p[j]])
				j--;
			else {
				t = p[i]; p[i] = p[j]; p[j] = t;
				i++; j--;
			}

		sort(i, r);
		sort(l, j);
	}
}

int main() {
	int n, i, j, k, mm, mi, mj, an;
	int ap[2000], pp[2003];

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		p[i] = i;
	}

	sort(0, n - 1);

	for (i = 0; i < n; i++)
		ap[i] = a[p[i]];

	mm = 1;
	for (i = 0; i < n; i++) {
		for (k = 2; k <= n; k++)
			pp[k] = i + 1;
			
		for (j = i + 1; j < n; j++) {
			if (ap[j] == ap[i])
				break;

			k = 1;
			pp[k] = j;
			an = ap[j];
			while (1) {
				if (pp[k] > pp[k + 1])
					pp[k + 1] = pp[k];
				k++;
				an += ap[j] - ap[i];
				while (pp[k] < n && ap[pp[k]] < an)
					pp[k]++;

				if (pp[k] == n || ap[pp[k]] != an)
					break;
			}

			if (k > mm) {
				mm = k;
				mi = i; mj = j;
			}
			
		}
	}

	if (mm == 1)
		printf("1\n1");
	else {
		printf("%d\n", mm);

		i = mi; j = mj; k = j + 1;
		while (1) {
			if (k < j + 1)
				k = j + 1;
			an = ap[j] + ap[j] - ap[i];
			while (k < n && ap[k] < an)
				k++;

			if (k == n || ap[k] != an)
				break;

			printf("%d ", p[i] + 1);
			i = j;
			j = k;
		}
		printf("%d %d", p[i] + 1, p[j] + 1);
	}

	return 0;
}
