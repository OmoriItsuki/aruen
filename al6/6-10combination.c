#include <stdio.h>

int combination(int n,int r){
	if(n==r||r==0)return 1;
	else return combination(n-1,r-1)+combination(n-1, r);
	}
	
int main(void){
	int n,r;
	printf("整数nを入力してください:");scanf("%d\n",&n);
	printf("整数rを入力してください:");scanf("%d\n",&r);
	printf("nCrは%dです。",combination(n, r));
	}