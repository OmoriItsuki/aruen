#include<stdio.h>

int input_score(){
	int a;
	printf("Input : ");
	scanf("%d",&a);

	return a;
}

void main(){
	int max=0;
	int a;
	do{
		while(1){
			a=input_score();
			if(a<=100 && a>= 0)
				break;
			else printf("再入力してください\n");
		}
		max=a>max?a:max;
	}while(a!=0);
	
	if(max==0)printf("あたいが入力されていません\n");
	else printf("入力された最大値は%dです。\n",max);
}

