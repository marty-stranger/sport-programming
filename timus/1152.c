#include <stdio.h>
#include <string.h>

int min(int a, int b) { return a < b ? a : b; }

int n, a[20], cs[1<<20];

int f(int b) {
    if (cs[b] != -1)
        return cs[b];

    int s = 0;
    if (b != (1<<n) - 1)
        for (int i = 0; i < n; i++)
            if ((b & 1<<i) != 0)
                s += a[i];

    int c = 1e9;
    for (int i = 0; i < n; i++) {
        int bb = b;
        for (int j = -1; j <= 1; j++)
            bb &= ~(1 << (i+j+n) % n);

        if (bb == b)
            continue;

        c = min(c, f(bb));
    }

    return cs[b] = c + s;
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    memset(cs, -1, sizeof cs);
    cs[0] = 0;
    printf("%d\n", f((1<<n) - 1));

    return 0;
}
