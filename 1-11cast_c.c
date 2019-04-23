#include<stdio.h>

int main(){
	int a,b;
	printf("Input a:");
	scanf("%d",&a);
	printf("Input b:");
	scanf("%d",&b);
	printf("a*3+b*4を3で割った値は%.5fです。\n",(float)(a*3+b*4)/3);
}
