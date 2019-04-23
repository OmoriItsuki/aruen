#include<stdio.h>

int sum(int a){
	return ((a+1)*a)/2;
}

void main(){
	int n;
	printf("正の整数:");
	scanf("%d",&n);
	printf("1から%dまでの和は%dです。\n",n,sum(n));
}
