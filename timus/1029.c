#include <stdio.h>

typedef struct res res;
struct res { long long a; int p; };

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
    const long long inf = 1e18;
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
        long long ss[501];
        ss[0] = 0;
        for (int j = 0; j < n; j++)
            ss[j+1] = ss[j] + a[i][j];

        for (int j = 0; j < n; j++) {
            res *r = &rs[i][j];
            r->a = inf;
            for (int k = 0; k < n; k++) {
                long long s = rs[i-1][k].a;
                if (j < k)
                    s += ss[k+1] - ss[j];
                else
                    s += ss[j+1] - ss[k];

                if (s < r->a) {
                    res t = {s, k};
                    *r = t;
                }
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
