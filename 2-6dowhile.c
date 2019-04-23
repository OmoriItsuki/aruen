#include<stdio.h>

void main(){
	int a;
	do{
		printf("Input a:");
		scanf("%d",&a);
		if(a>=0 && a<=10)
			printf("入力された数は%dです。\n",a);
		else 
			printf("0以上10以下で入力してください。\n");
	}while(a!=10);
}

