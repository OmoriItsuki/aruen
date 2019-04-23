#include<stdio.h>

void main(){
	int l;
	printf("辺の長さ：");
	scanf("%d",&l);

	for(int i=0;i<l;i++){
		for(int k=0;k<l;k++){
			if(k>=i){
				printf("*");
			}else{
				printf(" ");
			}
		}
		printf("\n");
	}
}
