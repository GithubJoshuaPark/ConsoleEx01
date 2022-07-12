#include "myheader.h"
#include <stdio.h>


int gi_num = 10;

void drawline(char *str) {
	if (str == NULL) {
		printf("=================\n");
	}
	else {
		printf("======[%s]=======\n", str);
	}
	
}

int add(int a, int b) {
	return a + b;
}