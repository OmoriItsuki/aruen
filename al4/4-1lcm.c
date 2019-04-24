#include <stdio.h>

int main(void){
	int x,y;
	printf("input x:");
	scanf("%d\n",&x);
	printf("input y:");
	scanf("%d\n",&y);
	
	int n = 1;
	while(n%x!=0||n%y!=0)n++;
	printf("%d\n",n);
	}