#include <stdio.h>
#include <string.h>

int main() {
    char s[100000+1];
    scanf("%s", s);

    int n = strlen(s);

    int c = 0;
    for (int i = 0; i < n; i++)
        if ('A' <= s[i] && s[i] <= 'Z')
            c++;

    int cc = 0, m = 1e9;
    for (int i = 0; i < n; i++) {
        int ccc = (i-cc) + (c-cc);

        if (ccc < m)
            m = ccc;

        if ('A' <= s[i] && s[i] <= 'Z')
            cc++;
    }

    int ccc = (n-cc) + (c-cc);
    if (ccc < m)
        m = ccc;

    printf("%d\n", m);

    return 0;
}
