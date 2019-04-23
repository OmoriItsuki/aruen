#include<stdio.h>

void main(){
	for(int i=9;i>0;i--){
		for(int k=9;k>0;k--){
			if(i*k/10==4 || i*k/10==6 || i*k%10==4 || i*k%10==6){
				continue;
			}else{
				printf("%02d ",i*k);
			}
		}
		printf("\n");
	}
	printf("\n");
}

