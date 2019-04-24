#include <stdio.h>
int main(void){
    
	int a,b,c,n=0;
	printf("Input a:");
	scanf("%d\n",&a);
	if(a%3==0)n++;
	
	printf("Input b:");
	scanf("%d\n",&b);
	if(b%3==0)n++;
	
	printf("Input c:");
	scanf("%d\n",&c);
	if(c%3==0)n++;
	
    printf("3変数の中に3の倍数は%d個含まれています。\n",n);
}