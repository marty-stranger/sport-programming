#include <stdio.h>

int main() {
    int n; scanf("%d", &n);

    long long a[501] = {0};
    a[0] = 1;

    for (int i = 1; i <= n; i++)
        for (int j = n; j >= i; j--)
            a[j] += a[j-i];

    printf("%lld\n", a[n] - 1);

    return 0;
}
