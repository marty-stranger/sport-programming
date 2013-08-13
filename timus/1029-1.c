#include <stdio.h>

typedef struct res res;
struct res { int a; int p; };

res rs[100][500];

void print(int i, int j) {
    if (i == 0) {
        printf("%d ", j+1);
        return;
    }

    int k = rs[i][j].p;
    print(i-1, k);

    if (k < j)
        for (int l = k; l <= j; l++)
            printf("%d ", l+1);
    else
        for (int l = k; l >= j; l--)
            printf("%d ", l+1);
}

int main() {
    const int inf = 1e9;
    int m, n; scanf("%d%d", &m, &n);

    int a[100][500];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    for (int i = 0; i < n; i++) {
        res r = {a[0][i], -1};
        rs[0][i] = r;
    }

    for (int i = 1; i < m; i++) {
        for (int j = 0; j < n; j++) {
            res r = {a[i][j] + rs[i-1][j].a, j};
            rs[i][j] = r;
        }

        for (int j = 1; j < n; j++) {
            res *r = &rs[i][j];
            int t = rs[i][j-1].a + a[i][j];
            if (t < r->a) {
                r->a = t;
                r->p = rs[i][j-1].p;
            }
        }

        for (int j = n-2; j >= 0; j--) {
            res *r = &rs[i][j];
            int t = rs[i][j+1].a + a[i][j];
            if (t < r->a) {
                r->a = t;
                r->p = rs[i][j+1].p;
            }
        }
    }

    int mi = 0;
    for (int i = 0; i < n; i++)
        if (rs[m-1][i].a < rs[m-1][mi].a)
            mi = i;

    print(m-1, mi);

    return 0;
}
