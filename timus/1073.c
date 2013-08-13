#include <stdio.h>

int min(int a, int b) { return a < b ? a : b; }

int main() {
    int n; scanf("%d", &n);

    int sn = 0, ss[300];
    for (int i = 1; i*i <= n; i++)
        ss[sn++] = i*i;

    int c[60000+1];

    c[0] = 0;
    for (int i = 1; i <= n; i++) {
        c[i] = 1e9;
        for (int j = 0; j < sn && ss[j] <= i; j++)
            c[i] = min(c[i], c[i - ss[j]] + 1);
    }

    printf("%d\n", c[n]);

    return 0;
}
