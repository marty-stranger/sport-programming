#include <stdio.h>

typedef struct rate rate;
struct rate { int l, c, i; };

typedef struct station station;
struct station { int l, c; };

int main() {
    rate rs[3];
    for (rate *r = rs; r != rs+3; r++)
        scanf("%d", &r->l);
    for (rate *r = rs; r != rs+3; r++)
        scanf("%d", &r->c);

    int n, s1, s2; scanf("%d%d%d", &n, &s1, &s2);
    s1--; s2--;

    if (s1 > s2) {
        int t = s1; s1 = s2; s2 = t;
    }

    station ss[10000];
    ss[0].l = 0;
    for (station *s = &ss[1]; s != &ss[n]; s++)
        scanf("%d", &s->l);

    for (rate *r = rs; r != rs+3; r++)
        r->i = s1;

    ss[s1].c = 0;
    for (int i = s1+1; i <= s2; i++) {
        station *s = &ss[i];
        s->c = 1e9;
        for (rate *r = rs; r != rs+3; r++) {
            while (ss[r->i].l + r->l < s->l)
                r->i++;

            if (r->i == i)
                continue;

            int t = ss[r->i].c + r->c;
            if (t < s->c)
                s->c = t;
        }
    }

    printf("%d\n", ss[s2].c);

    return 0;
}
