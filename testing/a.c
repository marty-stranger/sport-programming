#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
  int l = 1024 * 1024 * 500;

  char *arr = (char*) malloc(l);

  for (int i = 0; i < l; i++)
    arr[i] = i;

  printf("hey from hell\n");

  // sleep(5);
  for (int i = 0; i < 1000000000; i++) ;

  printf("hey from hell 2\n");

  return 0;
}
