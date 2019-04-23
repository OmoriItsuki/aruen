#include<stdio.h>

void main(){
	int list[9][2]={{0,4},{0,0},{3,0},{0,2},{0,1},{1,0},{4,0},{1,3},{1,0}};
	char str[3][5]={{"Team"},{"G"},{"T"}};
	int total[2]={0,0};
	int count=1;
	for(int i=0;i<3;i++){
		printf("%5s|",str[i]);
		for(int k=0;k<9;k++){
			if(i==0){
				printf(" %d",count);
				count++;
			}else{
				printf(" %d",list[k][i-1]);
				total[i-1]+=list[k][i-1];
			}
		}
		printf(" | ");
		if(i != 0){
			printf("%5d\n",total[i-1]);
		}else{
			printf("Total\n");
		}
	}
			
}	
