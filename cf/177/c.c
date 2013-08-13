#include <stdbool.h>
#include <stdio.h>

bool a1[2000][2000] = {0}, a2[2000][2000] = {0};

typedef struct comp comp;
struct comp { int c; bool b; };

comp cs[2000] = {0};

int c[2000];
int n, cn = 0;

void dfs(int i) {
    c[i] = cn;
    cs[cn].c++;

    for (int j = 0; j < n; j++)
        if (c[j] == -1 && a1[i][j])
            dfs(j);
}

int main() {
    scanf("%d", &n);

    int m; scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int u, v; scanf("%d%d", &u, &v); u--; v--;
        a1[u][v] = a1[v][u] = true;
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int u, v; scanf("%d%d", &u, &v); u--; v--;
        a2[u][v] = a2[v][u] = true;
    }

    for (int i = 0; i < n; i++)
        c[i] = -1;

    for (int i = 0; i < n; i++)
        if (c[i] == -1) {
            dfs(i);
            cn++;
        }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (c[i] == c[j] && a2[i][j])
                cs[c[i]].b = true;

    int max = 0;
    for (int i = 0; i < cn; i++)
        if (!cs[i].b && cs[i].c > max)
            max = cs[i].c;

    printf("%d\n", max);

    return 0;
}
