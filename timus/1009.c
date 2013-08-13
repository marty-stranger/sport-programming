#include <stdio.h>

int main() {
    int n, k; scanf("%d%d", &n, &k);

    int a = 0, b = k-1;

    for (int i = 0; i < n-1; i++) {
        int t = b;
        b = (k-1)*(a+b);
        a = t;
    }

    printf("%d\n", a + b);

    return 0;
}
