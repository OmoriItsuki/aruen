#include<stdio.h>

void main(){
	for(int i=9;i>0;i--){
		for(int k=9;k>0;k--){
			if(i*k>=10){
				printf("%02d ",i*k);
			}else{
				break;
			}
		}
		printf("\n");
	}
	printf("\n");
}

