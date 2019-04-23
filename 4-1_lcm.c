#include<stdio.h>

void main(){
	int x,y;
	printf("Input(x,y):");
	scanf("%d %d",&x,&y);
	int i=2;

	while(1){
		if(i%x==0 && i%y==0)break;

		i++;
	}
	printf("最小公倍数は%dです。\n",i);
}
