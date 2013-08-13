#include <stdio.h>

int main() {
    int n; scanf("%d", &n);

    static long long a[501][501] = {0};

    for (int i = 0; i <= 500; i++)
        a[0][i] = 1;

    for (int i = 1; i <= n; i++) {
        a[i][0] = 0;
        for (int j = 1; j <= i; j++)
            a[i][j] = a[i][j-1] + a[i-j][j-1];

        for (int j = i+1; j <= n; j++)
            a[i][j] = a[i][i];
    }

    printf("%lld\n", a[n][n] - 1);

    return 0;
}
