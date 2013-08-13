#include <stdio.h>
#include <string.h>

char m[6];

void find(int i, char *c) {
	int j, k, t;
	char a[6];

	if (i == 3) {
		for (j = 0; j < 6; j++)
			if (c[j] != m[j])
				break;

		if (j != 6 && c[j] < m[j])
			memcpy(m, c, sizeof(m));

		return; 
	}

	memcpy(a, c, sizeof(a));

	find(i+1, a);
	for (k = 0; k < 3; k++) {
		if (i == 0) {
			t = a[0]; a[0] = a[2]; a[2] = a[1]; a[1] = a[4]; a[4] = t;			
		} else if (i == 1) {
			t = a[0]; a[0] = a[3]; a[3] = a[1]; a[1] = a[5]; a[5] = t;
		} else {
			t = a[2]; a[2] = a[3]; a[3] = a[4]; a[4] = a[5]; a[5] = t;
		}

		find(i+1, a);
	}	
}

int main() {
	int n, i, j, k, p[10000], pn[10000], c[6];
	char b[6], a[10000][6], bb[10000];

	/*freopen("1015.in", "r", stdin);*/

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		for (j = 0; j < 6; j++) {
			scanf("%d", &b[j]); b[j]--;
		}

		memcpy(m, b, sizeof(b));

		find(0, b);
		memcpy(a[i], m, sizeof(m));
		p[i] = i;
	}

	for (i = 5; i >= 0; i--) {
		memset(c, 0, sizeof(c));

		for (j = 0; j < n; j++)
			c[a[j][i]]++;

		for (j = 1; j < 6; j++)
			c[j] += c[j-1];

		for (j = n-1; j >= 0; j--) {
			pn[c[a[p[j]][i]]-1] = p[j];
			c[a[p[j]][i]]--;
		}
		memcpy(p, pn, sizeof(p));
	}

	k = 1;
	for (i = 1; i < n; i++) {
		for (j = 0; j < 6; j++)
			if (a[p[i]][j] != a[p[i-1]][j])
				break;

		if (j != 6)
			k++;
		
	}

	printf("%d", k);

	memset(bb, 0, sizeof(bb));
	for (i = 0; i < n; i++)
		if (!bb[i]) {
			printf("\n%d", i+1); bb[i] = 1;
			for (j = i+1; j < n; j++)
				if (!bb[j]) {
					for (k = 0; k < 6; k++)
						if (a[i][k] != a[j][k])
							break;
					if (k == 6) {
						printf(" %d", j+1);
						bb[j] = 1;
					}
				}
		}

	/*printf("%d", p[0]+1);
	for (i = 1; i < n; i++) {
		for (j = 0; j < 6; j++)
			if (a[p[i]][j] != a[p[i-1]][j])
				break;

		if (j != 6)
			printf("\n%d", p[i]+1);
		else
			printf(" %d", p[i]+1);		
	}*/
	
	return 0;
}

