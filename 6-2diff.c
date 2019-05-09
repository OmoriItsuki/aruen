#include<stdio.h>

#define diff(x,y) x>y ? x-y : y-x

void main() {
	unsigned int a, b;
	printf("a:");
	scanf("%d", &a);
	printf("b:");
	scanf("%d", &b);
	printf("the diff is %d\n", diff(a, b));

}
