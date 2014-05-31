#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct { int x, y; } point;

char a[2000][2001];
point q[3000 * 3000];
bool b[3000][3000] = {0};

int main() {
  int n, m, v;
  scanf("%d%d%d", &n, &m, &v);

  point s, e;
  scanf("%d%d%d%d", &s.x, &s.y, &e.x, &e.y);
  s.x--; s.y--; e.x--; e.y--;

  scanf("\n");

  for (int i = 0; i < n; i++)
    gets(a[i]);

  // puts("ok");

  int qs = 0, qe = 0;
  q[qe++] = s;

  int dx[4] = {1, 0, -1, 0},
    dy[4] = {0, 1, 0, -1};

  while (qs != qe) {
    point p = q[qs++];

    printf("dequeue: x=%d y=%d\n", p.x, p.y);

    for (int i = 0; i < 4; i++) {
      point pp = (point){p.x + dx[i] * v, p.y + dy[i] * v};

      int d = 0;

      void dfs(point p3) {
        printf("dfs: x=%d y=%d\n", p3.x, p3.y);

        d++;

        printf("d = %d\n", d);

        if (abs(p3.x - p.x) + abs(p3.y - p.y) > v)
          return;

        if (b[v + p3.x][v + p3.y])
          return;
        b[v + p3.x][v + p3.y] = true;

        // printf("c = %c\n", a[p3.x][p3.y]);
        if (0 <= p3.x && p3.x < n && 0 <= p3.y && p3.y < m && a[p3.x][p3.y] == 'F')
          q[qe++] = p3;

        for (int i = 0; i < 4; i++) {
          point p4 = (point){p3.x + dx[i], p3.y + dy[i]};
          dfs(p4);
        }
      }

      dfs(pp);
    }
  }

  for (int i = 0; i < qe; i++)
    if (abs(q[i].x - e.x) +  abs(q[i].y - e.y) <= v) {
      puts("Hello, Deimos!");
      return 0;
    }

  puts("Dire victory");

  return 0;
}

