#include<stdio.h>

void main(){
	int a;
	printf("Input a:");
	scanf("%d",&a);
	if(a%3 == 0)
		printf("3の倍数です。\n");
	else 
		printf("3の倍数ではありません。\n");
}

