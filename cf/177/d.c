#include <stdio.h>

int m, mod, b[200000];

void set(int i) {
    if (i % 2)
        i ^= 1;

    b[i/2] = (b[i] + b[i^1]) % mod;
}

int query(int l, int r) {
    l += m; r += m;

    int s1 = 0, s2 = 0;
    while (l <= r) {
        if (l & 1) {
            s1 = (s1 + b[l]) % mod;
            l++;
        }

        if (!(r & 1)) {
            s2 = (s2 + b[r]) % mod;
            r--;
        }

        l /= 2; r /= 2;
    }

    return (s1 + s2) % mod;
}

int main() {
    int n; scanf("%d%d%d", &n, &m, &mod);

    int a[100000];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (int i = m; i < 2*m; i++)
        scanf("%d", &b[i]);

    for (int i = 2*m-1; i > 1; i -= 2)
        set(i);

    for (int i = 0; i < n; i++) {
        int l = i+m-n, r = i;
        if (l < 0)
            l = 0;
        if (r > m-1)
            r = m-1;

        // printf("i = %d l = %d r = %d\n", i+1, l+1, r+1);

        // printf("q = %d\n", query(l, r));

        int s = (a[i] + query(l, r)) % mod;

        printf("%d ", s);
    }

    putchar('\n');

    return 0;
}
