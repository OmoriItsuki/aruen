#include<stdio.h>

void main(){
	for(int i=9;i>0;i--){
		for(int k=9;k>0;k--){
			printf("%02d ",i*k);
		}
		printf("\n");
	}
	printf("\n");
}

