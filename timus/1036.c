#include <stdio.h>
#include <string.h>

const int base = 1000000000;

typedef int big[20];

void set(big a, int b) {
    memset(a, -1, sizeof(big));
    a[0] = b;
}

void add(big a, big b) {
    int c = 0;

    for (; *a != -1 || *b != -1; a++, b++) {
        if (*a != -1)
            c += *a;
        if (*b != -1)
            c += *b;
        *a = c % base;
        c /= base;
    }

    if (c != 0)
        *a = c;
}

void copy(big a, big b) {
    memset(a, -1, sizeof(big));
    for (; *b != -1; a++, b++)
        *a = *b;
}

int min(int a, int b) { return a < b ? a : b; }

void mul(big a, big b) {
    big r;
    set(r, 0);

    for (int i = 0; a[i] != -1; i++) {
        long long c = 0;

        int j = 0;
        for (; b[j] != -1; j++) {
            c += 1ll * a[i] * b[j];
            if (r[i+j] != -1)
                c += r[i+j];
            r[i+j] = c % base;
            c /= base;
        }

        while (c != 0) {
            r[i+j] = c % base;
            c /= base;
        }
    }

    copy(a, r);
}

void print(big a) {
    int *b = a;
    while (*b != -1)
        b++;

    b--;
    printf("%d", *b);

    while (b != a) {
        b--;
        printf("%09d", *b);
    }
}

int main() {
    int n, s; scanf("%d%d", &n, &s);

    if (s % 2 != 0 || s > 9*2*n) {
        printf("%d\n", 0);
        return 0;
    }

    static big c[51][50*9+1];

    set(c[0][0], 1);
    for (int j = 1; j <= 50*9; j++)
        set(c[0][j], 0);

    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= min(n*9, s/2); j++) {
            set(c[i][j], 0);
            for (int k = 0; k <= 9; k++)
                if (j-k >= 0)
                    add(c[i][j], c[i-1][j-k]);
        }

    big r;
    copy(r, c[n][s/2]);
    mul(r, r);

    print(r);
    putchar('\n');

    return 0;
}
