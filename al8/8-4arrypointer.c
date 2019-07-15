#include <stdio.h>

int main(void){
	int ary[10]={1,3,5,7,9,11,13,15,17,19};
	int i,sum,*p;
	
	sum=0;
	for(i=0,p=&ary;i<10;i++,p++)
	{
		sum+=*p;
	}
	printf("Total :%d\n",sum);
	}
