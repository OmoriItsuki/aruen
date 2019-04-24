#include <stdio.h>

int main(void){
	int score[2][9]={{0,0,0,0,0,0,0,0,0},
	                 {0,0,0,0,0,0,0,0,0}};
	
	printf("Team |");
	for(int i = 1;i<=9;i++)
	{
		printf(" %d",i);
	}
	printf(" | Total\n");
	
	for(int i =0;i<2;i++)
	{
		int total=0;
		printf("%s    |",i==0?"G":"T");
		for(int j =0;j<9;j++)
		{
			printf(" %d",score[i][j]);
			total+=score[i][j];
		}
		printf(" | %d\n",total);
	}
	}
