#include <stdio.h>

int fibonacci(int n){
	switch(n)
	{
		case 0:return 0;break;
		case 1:return 1;break;
		default:return fibonacci(n-1)+fibonacci(n-2);break;
	}
	}
	
int main(void){
	int n;
	printf("正の整数nを入力してください:");
	scanf("%d\n",&n);
	printf("F%dは%dです。",n,fibonacci(n));
	}
