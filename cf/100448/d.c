/* ok, 12cs, 300kb */
#include <stdio.h>
#include <string.h>

#define m 16384
const long long mod = 1000000000 + 7;

int main() {
  int n; scanf("%d", &n);

  int as[10000];
  for (int i = 0; i < n; i++)
    scanf("%d", &as[i]);

  long long cs1[m] = {0};
  cs1[0] = 1;

  long long cs2[m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      cs2[j] = (cs1[j] + (2 * cs1[j ^ as[i]])) % mod;

    memcpy(cs1, cs2, sizeof(cs1));
  }

  printf("%I64d\n", cs1[0]);
   
  return 0;
}
