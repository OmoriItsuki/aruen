#include<stdio.h>

int main(){
	int a,b;
	printf("Input a:");
	scanf("%d",&a);
	printf("Input b:");
	scanf("%d",&b);
	printf("aとbの平均は%.1fです。\n",(float)(a+b)/2);
}
