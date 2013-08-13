#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef __cplusplus
	#include <stdbool.h>
#endif 

void f() {
	int a[5] = { 5, 4, 3, 2, 1 };
	for (int i = 0; i < 5; i++)
		printf("%d\n", a[i]);
}

void g() {
	int a[5] = {};

	for (int i = 0; i < 5; i++)
		printf("%d\n", a[i]);
}

int main() {
	f();
	g();
	
	return 0;
}
