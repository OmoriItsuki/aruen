#include <stdio.h>

#define diff(x,y) (x>y?x-y:y-x)

int main(void){
	unsigned int a,b;
	printf("aの値を正の整数で入力してください:");scanf("%u\n",&a);
	printf("bの値を正の整数で入力してください:");scanf("%u\n",&b);
	printf("aとbの差は%uです。\n",diff(a, b));
	}