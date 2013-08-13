#include <stdio.h>
#include <string.h>

const int base = 1000000000;

typedef int big[1000];

void set(big a, int b) {
    memset(a, -1, sizeof(big));
    a[0] = b;
}

void copy(big a, big b) {
    while (*b != -1) {
        *a = *b;
        a++; b++;
    }
    *a = -1;
}

void add(big a, big b) {
    int c = 0;

    while (*a != -1 || *b != -1) {
        if (*a != -1)
            c += *a;
        if (*b != -1)
            c += *b;
        *a = c % base;
        c /= base;
        a++; b++;
    }

    if (c != 0) {
        *a = c;
        a++;
        *a = -1;
    }
}

void mul(big a, int b) {
    long long c = 0;

    while (*a != -1) {
        c += 1ll * *a * b;
        *a = c % base;
        c /= base;
        a++;
    }

    while (c != 0) {
        *a = c % base;
        c /= base;
        a++;
    }

    *a = -1;
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
    int n, k, i;
    big a, b;
    
    scanf("%d%d", &n, &k);

    set(a, 0);
    set(b, k-1);

    for (i = 0; i < n-1; i++) {
    big t;
        copy(t, b);
        add(b, a);
        mul(b, k-1);
        copy(a, t);
    }
    
    add(b, a);
    print(b);
    putchar('\n');

    return 0;
}
