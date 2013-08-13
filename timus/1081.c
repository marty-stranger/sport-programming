#include <stdio.h>

int main() {
    int n, k; scanf("%d%d", &n, &k);

    int c[45] = {1, 2};
    for (int i = 2; i <= n; i++)
        c[i] = c[i-2] + c[i-1];

    if (k > c[n]) {
        puts("-1");
        return 0;
    }
    
    int s[45] = {0};

    for (int i = n-1; i >= 0; i--)
        if (k > c[i]) {
            s[i] = 1;
            k -= c[i];
        }

    for (int i = n-1; i >= 0; i--)
        printf("%d", s[i]);
    putchar('\n');

    return 0;
}
