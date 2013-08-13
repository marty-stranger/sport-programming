#include <stdio.h>

int main() {
    int n; scanf("%d", &n);

    static long long a[501][501] = {0};

    a[0][0] = 1;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++) {
            a[i][j] = 0;
            for (int k = 0; k <= j-1; k++)
                a[i][j] += a[i-j][k];
        }
           
    long long s = 0;
    for (int i = 0; i <= n; i++)
        s += a[n][i];

    printf("%lld\n", s - 1);

    return 0;
}
