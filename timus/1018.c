// #include <stdbool.h>
#include <stdio.h>

typedef struct vertex vertex;
struct vertex { int i, w, n, m[101]; vertex *a[2]; bool b; };

typedef struct edge edge;
struct edge { vertex *u, *v; int w; };

int max(int a, int b) { return a > b ? a : b; }

int count(vertex *u, int k) {
    if (u->m[k] != -1)
        return u->m[k];

    if (k == 0)
        return u->w;

    if (u->n == 0 && k > 0)
        return -1e9;

    int m = max(count(u->a[0], k-1), count(u->a[1], k-1));

    for (int l = 0; l <= k-2; l++)
        m = max(m, count(u->a[0], l) + count(u->a[1], k-2-l));

    return u->m[k] = m + u->w;
}

int main() {
    int n, k; scanf("%d%d", &n, &k);

    vertex vs[100] = {0};

    for (vertex *u = vs; u != vs+n; u++) {
        u->i = u - vs;
        for (int i = 0; i <= k; i++)
            u->m[i] = -1;
    }

    edge es[100] = {0};
    for (int i = 0; i < n-1; i++) {
        int ui, vi, w; scanf("%d%d%d", &ui, &vi, &w);
        ui--; vi--;

        edge e = {vs + ui, vs + vi, w};
        es[i] = e;
    }

    vs[0].b = true;
    for (int i = 0; i < n; i++)
        for (edge *e = es; e != es+n-1; e++) {
            vertex *u = e->u, *v = e->v;
            if ((u->b && !v->b) || (!u->b && v->b)) {
                if (v->b) {
                    vertex *t = u; u = v; v = t;
                }

                u->a[u->n++] = v;
                v->w = e->w;
                v->b = true;
            }
         }

    printf("%d\n", count(&vs[0], k));

    return 0;
}
