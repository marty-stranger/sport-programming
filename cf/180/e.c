#include <stdio.h>

typedef struct color color;
struct color { int p, l, c, s; };

int main() {

    int n, m, k; scanf("%d%d%d", &n, &m, &k);

    color cs[m];
    for (int i = 0; i < m; i++)
        cs[i].p = -1;

    int nx[n];

    int max = -1;
    for (int i = 0; i < n; i++) {
        int ci; scanf("%d", &ci); ci--;

        color *c = &cs[ci];

        if (c->p == -1) {
            c->l = i;
            c->s = 0;
            c->c = 1;
        } else {
            nx[c->p] = i;

            c->c++; c->s += i - c->p - 1;

            while (c->s > k) {
                c->s -= nx[c->l] - c->l - 1;
                c->l = nx[c->l];
                c->c--;
            }
        }

        if (c->c > max)
            max = c->c;

        c->p = i;
    }

    printf("%d\n", max);

    return 0;
}
