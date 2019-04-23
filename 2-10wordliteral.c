#include<stdio.h>

void main(){
	int a;
	do{
		printf("10以上20未満の整数を入力してください。");
		scanf("%d",&a);
	}while(a<10 && a>=20);

	int i=0;
	while(i<a){
		printf("++");
		i++;
	}
	printf("\n");
}
