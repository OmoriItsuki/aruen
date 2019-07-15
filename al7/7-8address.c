#include <stdio.h>

int main(void){
	char c[3][2];
	int i[3][2];
	double d[3][2];
	
	for(int j=0;j<3;j++)
	{
		for(int k=0;k<2;k++)
		{
			printf("c[%d][%d]のアドレス:%d\n",j,k,&c[j][k]);
		}
	}	
	for(int j=0;j<3;j++)
	{
		for(int k=0;k<2;k++)
		{
			printf("i[%d][%d]のアドレス:%d\n",j,k,&i[j][k]);
		}
	}	
	for(int j=0;j<3;j++)
	{
		for(int k=0;k<2;k++)
		{
			printf("d[%d][%d]のアドレス:%d\n",j,k,&d[j][k]);
		}
	}
	}
