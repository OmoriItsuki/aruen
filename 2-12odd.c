#include<stdio.h>

void main(){
	int k;
	printf("Input k:");
	scanf("%d",&k);

	for(int i=1;i<=k;i=i+2){
		printf("%d ",i);
	}
	printf("\n");
}
