#include<stdio.h>

void main(){
	int a,b,c;
	printf("Input a:");
	scanf("%d",&a);
	printf("Input b:");
	scanf("%d",&b);
	printf("Input c:");
	scanf("%d",&c);

	int count=0;

	if(a%3==0)count++;
	if(b%3==0)count++;
	if(c%3==0)count++;

	printf("3変数の中に3の倍数は%d個含まれています。\n",count);
}

