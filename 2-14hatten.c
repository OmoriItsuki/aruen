#include<stdio.h>

void main(){
	int k;
	int count=0;
	printf("Input k:");
	scanf("%d",&k);

	for(int i=1;i<=k;i++){
		if(k%i==0){
			printf("%d ",i);
			count++;
		}
	}
	printf("\n約数の総数は%d個です。\n",count);
}

