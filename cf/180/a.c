#include <stdio.h>

typedef struct info info;
struct info { int i, j; };

typedef struct op op;
struct op { int i, j; };

int main() {
    int n, m; scanf("%d%d", &n, &m);

    info is[200];

    for (int i = 0; i < n; i++)
        is[i].i = -1;

    int ks[m];
    for (int i = 0; i < m; i++) {
        scanf("%d", &ks[i]);

        for (int j = 0; j < ks[i]; j++) {
            int ii; scanf("%d", &ii); ii--;
            is[ii] = (info){i, j};
        }
    }

    int opn = 0;
    op ops[400];

    int di = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < ks[i]; j++) {
            if (is[di].i != i || is[di].j != j) {
                if (is[di].i != -1) {
                    int fi = 0;
                    while (fi < n && is[fi].i != -1)
                        fi++;

                    ops[opn++] = (op){di, fi};
                    is[fi] = is[di];
                    is[di].i = -1;
                }

                int ii;
                for (int l = 0; l < n; l++)
                    if (is[l].i == i && is[l].j == j) {
                        ii = l;
                        break;
                    }

                is[di] = (info){i, j};
                ops[opn++] = (op){ii, di};
                is[ii].i = -1;
            }

            di++;
        }
    }

    printf("%d\n", opn);
    for (int i = 0; i < opn; i++)
        printf("%d %d\n", ops[i].i+1, ops[i].j+1);

    return 0;
}
