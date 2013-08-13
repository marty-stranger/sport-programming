#include <stdio.h>

int main() {
    int n; scanf("%d", &n);

    int s = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            int a; scanf("%d", &a);
            if (i == j || i == n-1-j || i == n/2 || j == n/2)
                s += a;
        }

    printf("%d\n", s);

    return 0;
}
