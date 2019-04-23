#include<stdio.h>

void main(){
	int a;
	int count=0;
	int sum=0;
	do{
		printf("Input a:");
		scanf("%d",&a);
		if(a>=0 && a<=10){
			printf("入力された数は%dです。\n",a);
			if(a==0)count++;
			sum+=a;
		}
		else 
			printf("0以上10以下で入力してください。\n");
	}while(a!=10);
	printf("0は%d回入力されました。\n入力された値の合計は%dです。\n",count,sum);
}

