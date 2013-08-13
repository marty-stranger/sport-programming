// #include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef int bool;
const bool true = 1;
const bool false = 0;

typedef struct vertex vertex;
struct vertex { int c, an, ac; vertex **a; };

typedef struct { int a, b; } res;

int max(int a, int b) { return a > b ? a : b; }

vertex vs[6000] = {0};

res dfs(vertex *u) {
    int a = 0, b = u->c;
    vertex **v;
    res r;

    for (v = &u->a[0]; v != &u->a[u->an]; v++) {
        res r = dfs(*v);
        a += max(r.a, r.b);
        b += r.a;
    }

    r.a = a; r.b = b;
    return r;
}

int main() {
    int n, i;
    vertex *u;
    bool b[6000] = {0};
    res r;

    scanf("%d", &n);

    for (u = &vs[0]; u != &vs[n]; u++)
        scanf("%d", &u->c);

    for (;;) {
        int ui, vi;
	vertex *u, *v;
	
	scanf("%d%d", &ui, &vi);

        if (ui == 0 && vi == 0)
            break;

        ui--; vi--;

        u = &vs[ui]; v = &vs[vi];
        if (v->ac < v->an + 1) {
            v->ac++;
            v->a = (vertex**) realloc(v->a, v->ac * sizeof(vertex *));
        }

        b[ui] = true;
                  
        v->a[v->an++] = u;
    }

    for (i = 0; i < n; i++)
        if (!b[i]) {
            u = &vs[i];
            break;
        }

    r = dfs(u);
    printf("%d\n", max(r.a, r.b));

    return 0;
}
