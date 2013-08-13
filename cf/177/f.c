#include <stdio.h>

typedef struct option option;
struct option { int h, w, r; };

option os[100];

int k, t, cnt = 0;
int cs[100001] = {0};

void gen(int p1, int p2, int i, int s) {
    if (i == k) {
        cs[s]++;
        cnt++;
        return;
    }

    gen(p1, p2, i+1, s);

    option *o = &os[i];

    if ((p1 & (1 << o->h)) == 0 && (p2 & (1 << o->w)) == 0)
        gen(p1 | (1 << o->h), p2 | (1 << o->w), i+1, s + o->r);
}

int main() {
    int n; scanf("%d%d%d", &n, &k, &t);

    for (int i = 0; i < k; i++) {
        option *o = &os[i];
        scanf("%d%d%d", &o->h, &o->w, &o->r);
        o->h--; o->w--;
    }

    gen(0, 0, 0, 0);

    int s = 0;
    for (int i = 0; i <= 100000; i++) {
        // printf("i = %d -> %d\n", i, cs[i]);
        s += cs[i];

        if (t <= s) {
            printf("%d\n", i);
            return 0;
        }
    }

    return 0;
}
