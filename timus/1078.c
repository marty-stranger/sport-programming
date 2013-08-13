#include <stdio.h>

typedef struct seg seg;
struct seg { int l, r, c, i; seg *p; };

int max(int a, int b) { return a > b ? a : b; }

int main() {
    int n; scanf("%d", &n);

    seg ss[500] = {0};

    for (seg *s = ss; s != ss+n; s++) {
        scanf("%d%d", &s->l, &s->r);
        s->i = s-ss;
    }

    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++)
            if (ss[j].l < ss[i].l) {
                seg t = ss[i]; ss[i] = ss[j]; ss[j] = t;
            }

    ss[0].c = 1;
    for (seg *s = &ss[1]; s != &ss[n]; s++) {
        s->c = 1;
        s->p = NULL;
          
        for (seg *t = &ss[0]; t != s; t++)
            if (t->l != s->l && t->r > s->r)
                if (t->c + 1 > s->c) {
                    s->c = t->c + 1;
                    s->p = t;
                }
    }
    
    seg *s = &ss[0];
    for (seg *t = &ss[1]; t != &ss[n]; t++)
        if (t->c > s->c)
            s = t;

    printf("%d\n", s->c);

    while (s != NULL) {
        printf("%d ", s->i + 1);
        s = s->p;
    }
    putchar('\n');

    return 0;
}
