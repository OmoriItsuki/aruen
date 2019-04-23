#include<stdio.h>

void main(){
	int a,b,c;
	printf("Input a:");
	scanf("%d",&a);
	printf("Input b:");
	scanf("%d",&b);
	printf("Input c:");
	scanf("%d",&c);

	int max=INT_MIN;

	if(a%2 == 0)max=a;
       	if(b%2 == 0)max=b>max?b:max;
	if(c%2 == 0)max=c>max?c:max;	

	
	printf("3変数の中に3の倍数は%d個含まれています。\n",count);
}

