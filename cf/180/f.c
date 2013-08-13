#include <stdio.h>

int main() {
    int n; scanf("%d", &n);

    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int b[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &b[i]);

    int p[n];
    for (int i = 0; i < n; i++)
        p[a[i]-1] = b[i];

    for (int i = 0; i < n; i++)
        printf("%d ", p[i]);
    putchar('\n');

    return 0;
}
