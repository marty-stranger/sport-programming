#include <stdio.h>
#include <string.h>

int min(int a, int b) { return a < b ? a : b; }

int main() {
    int n, k, i, j, l, bs[500], ss[501] = {0}, cs[501][501];
    
    scanf("%d%d", &n, &k);

    for (i = 0; i < n; i++)
        scanf("%d", &bs[i]);

    for (i = 0; i < n; i++)
        ss[i+1] = ss[i] + bs[i];

    cs[0][0] = 0;
    for (i = 1; i <= n; i++)
        cs[0][i] = 1e9;

    for (i = 1; i <= n; i++) {
        cs[i][0] = 1e9;
        for (j = 1; j <= k; j++) {
            cs[i][j] = 1e9;
            for (l = 1; l <= i; l++) {
                int b = ss[i] - ss[l-1];
                cs[i][j] = min(cs[i][j], cs[l-1][j-1] + b * (i-l+1 - b));
            }
        }
    }

    printf("%d\n", cs[n][k]);

    return 0;
}
