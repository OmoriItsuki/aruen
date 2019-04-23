#include<stdio.h>

int main(){
	int a,b;
	printf("Input a:");
	scanf("%d",&a);
	printf("Input b:");
	scanf("%d",&b);
	printf("a+bの符号を反転した値-(a+b)は%dです。\n",-1*(a+b));
}
