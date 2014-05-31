#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct { int x, y; } point;

char a[2000][2001];
point q[4000 * 4000];
bool b[4000][4000] = {0};

point stack[4000 * 4000];

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

    // printf("dequeue: x=%d y=%d\n", p.x, p.y);

    for (int i = 0; i < 5; i++) {
      point pp;
      if (i < 4)
        pp = (point){p.x + dx[i] * v, p.y + dy[i] * v};
      else
        pp = (point){p.x, p.y};

      if (abs(pp.x - p.x) + abs(pp.y - p.y) > v)
        continue;
      if (b[v + pp.x][v + pp.y])
        continue;

      int ss = 0;
      stack[ss++] = pp;
      b[v + pp.x][v + pp.y] = true;

      if (0 <= pp.x && pp.x < n && 0 <= pp.y && pp.y < m && a[pp.x][pp.y] == 'F')
        q[qe++] = pp;

      while (ss != 0) {
        point pp = stack[--ss];

        // printf("c = %c\n", a[p3.x][p3.y]);

        for (int i = 0; i < 4; i++) {
          point ppp = (point){pp.x + dx[i], pp.y + dy[i]};

          if (abs(ppp.x - p.x) + abs(ppp.y - p.y) > v)
            continue;
          if (b[v + ppp.x][v + ppp.y])
            continue;

          b[v + ppp.x][v + ppp.y] = true;
          
          if (0 <= ppp.x && ppp.x < n && 0 <= ppp.y && ppp.y < m && a[ppp.x][ppp.y] == 'F')
            q[qe++] = ppp;

          stack[ss++] = ppp;
        }
      }
    }

    /* for (int dx = -v; dx <= v; dx++)
      for (int dy = -v; dy <= v; dy++) {
        int xx = p.x + dx, yy = p.y + dy;
        if (abs(xx - p.x) + abs(yy - p.y) <= v && 0 <= xx && xx < n && 0 <= yy && yy < m && !b[xx + v][yy + v] && a[xx][yy] == 'F') {
          // printf("missed: %d %d\n", xx, yy);
          q[qe++] = (point){xx, yy};
        }
      } */
  }

 /* for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (!b[v + i][v + j] && a[i][j] == 'F')
        printf("unbrowsed: %d %d\n", i, j); */

  // printf("qe = %d\n", qe);

  for (int i = 0; i < qe; i++)
    if (abs(q[i].x - e.x) +  abs(q[i].y - e.y) <= v) {
      puts("Hello, Deimos!");
      return 0;
    }

  puts("Dire victory");

  return 0;
}

