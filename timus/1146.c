#include <stdio.h>

int max(int a, int b) { return a > b ? a : b; }

int main() {
    int n; scanf("%d", &n);

    int a[100][100];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    int s[101][101] = {0};

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            s[i][j] = a[i-1][j-1] + s[i][j-1] + s[i-1][j] - s[i-1][j-1];

    int r = -1e9;
    for (int i1 = 0; i1 < n; i1++)
        for (int i2 = i1; i2 < n; i2++)
            for (int j1 = 0; j1 < n; j1++)
                for (int j2 = j1; j2 < n; j2++)
                    r = max(r, s[i2+1][j2+1] - s[i1][j2+1] - s[i2+1][j1] + s[i1][j1]);

    printf("%d\n", r);

    return 0;
}
