#include<stdio.h>

void main(){
	int k;
	printf("素数判定する数字を入力してください。\n");
	scanf("%d",&k);
	int flag=0;
	int i=2;
	while(i*i<=k){
		if(k%i==0){
			printf("これは素数ではありません。\n");
			flag=1;
			break;
		}else{
			i++;
		}

	}
	if(flag==0)printf("これは素数です。\n");

}
