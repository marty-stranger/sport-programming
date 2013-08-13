#include <stdio.h>

int cs[31]; // answer for 1 : 1<<i

int f(int a, int p) {
    int c = 1<<p;
    if (a == c)
        return cs[p];
    if (a < c)
        return f(a, p-1);

    return cs[p] + p-1 + f(a - c, p-1);
}

int main() {
    int a, b; scanf("%d%d", &a, &b);

    if (a > b) {
        int t = a; a = b; b = t;
    }

    cs[1] = 0;
    for (int i = 2; i <= 30; i++)
        cs[i] = 2*cs[i-1] + (i-1);

    printf("%d\n", f(b, 30) - f(a, 30));

    return 0;
}
