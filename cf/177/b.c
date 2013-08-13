#include <stdio.h>

int main() {
    int n; scanf("%d", &n);

    long long s = n;
    for (int i = 2; i*i <= n; i++) {
        while (n % i == 0) {
            n /= i;
            s += n;
        }
    }

    if (n != 1)
        s += 1;

    printf("%I64d\n", s);

    return 0;
}
